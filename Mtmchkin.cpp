
#include "Mtmchkin.h"

#include "utilities.h"

bool validatePlayerName(string name)
{
    int i;

    // player name must be between 3 and 15 character
    if (name.length() < 3 || name.length() > 15)
        return false;

    // player name must contain alphabets only
    for (i = 0; i < (int)name.length(); i++)
    {
        if (isalpha(name[i]) == 0)
            return false;
    }
    return true;
}

Mtmchkin::Mtmchkin(const string &deckPath, const string &playersPath)
{
    this->readDeckFile(deckPath);
    this->readPlayersFile(playersPath);
    this->m_turnIndex = 1;
}

void Mtmchkin::readDeckFile(const string &deckPath)
{
    ifstream deck_file(deckPath);
    string card_name;
    int gang_size, remaining_monsters;
    bool encounter_present = false;

    while (deck_file >> card_name)
    {
        if (card_name == "Goblin")
        {
            this->m_deck.push_back(shared_ptr<Encounter>(new Encounter(shared_ptr<Monster>(new Goblin()))));
            encounter_present = true;
        }

        else if (card_name == "Giant")
        {
            this->m_deck.push_back(shared_ptr<Encounter>(new Encounter(shared_ptr<Monster>(new Giant()))));
            encounter_present = true;
        }

        else if (card_name == "Dragon")
        {
            this->m_deck.push_back(shared_ptr<Encounter>(new Encounter(shared_ptr<Monster>(new Dragon()))));
            encounter_present = true;
        }

        else if (card_name == "SolarEclipse")
            this->m_deck.push_back(shared_ptr<Card>(new SolarEclipse()));

        else if (card_name == "PotionsMerchant")
            this->m_deck.push_back(shared_ptr<Card>(new PotionsMerchant()));

        else if (card_name == "Gang")
        {
            if (!(deck_file >> gang_size))
            {
                throw InvalidCardsFileException();
            }
            if (gang_size < 2)
                throw InvalidCardsFileException();

            shared_ptr<Gang>gang(new Gang(gang_size));

            remaining_monsters = gang_size;
            while (remaining_monsters > 0)
            {
                if (!(deck_file >> card_name))
                    throw InvalidCardsFileException();
                else if (card_name == "Goblin")
                    gang->addMonster(shared_ptr<Monster>(new Goblin()));
                else if (card_name == "Giant")
                    gang->addMonster(shared_ptr<Monster>( new Giant()));
                else if (card_name == "Dragon")
                    gang->addMonster(shared_ptr<Monster>( new Dragon()));
                else if (card_name == "Gang")
                {
                    if (!(deck_file >> gang_size))
                        throw InvalidCardsFileException();
                    if (gang_size < 2)
                        throw InvalidCardsFileException();
                    remaining_monsters += gang_size;
                }
                else
                    throw InvalidCardsFileException();
                remaining_monsters--;
            }
            this->m_deck.push_back(shared_ptr<Card>(new Encounter(gang)));
            encounter_present = true;
        }
        else
            throw InvalidCardsFileException();
    }
    deck_file.close();
    if (this->m_deck.size() < 2)
        throw InvalidCardsFileException();
    if (!encounter_present)
        throw InvalidCardsFileException();
}

void Mtmchkin::readPlayersFile(const string &playersPath)
{
    ifstream players_file(playersPath);
    string name, job, beh;
    while (true)
    {
        if (!(players_file >> name))
            break;
        if (!(players_file >> job))
            throw InvalidPlayersFileException();
        if (!(players_file >> beh))
            throw InvalidPlayersFileException();

        if (!validatePlayerName(name))
            throw InvalidPlayersFileException();

        shared_ptr<Behavior>behavior;
        if (beh == "Responsible")
            behavior = shared_ptr<Behavior>(new ResponsibleBehavior());
        else if (beh == "RiskTaking")
            behavior = shared_ptr<Behavior>(new RiskTakingBehavior());
        else
            throw InvalidPlayersFileException();

        shared_ptr<Player> player;
        if (job == "Warrior")
            player = shared_ptr<Player>(new Warrior(name, behavior));
        else if (job == "Sorcerer")
            player =shared_ptr<Player>( new Sorcerer(name, behavior));
        else
            throw InvalidPlayersFileException();

        this->m_players.push_back(player);
    }
    players_file.close();
    if (this->m_players.size() < 2 || this->m_players.size() > 6)
        throw InvalidPlayersFileException();
}

shared_ptr<Card>Mtmchkin::drawCard()
{
    shared_ptr<Card>card;
    card = this->m_deck.front();
    this->m_deck.pop_front();
    this->m_deck.push_back((card));
    return card;
}

void Mtmchkin::playTurn(Player &player)
{
    shared_ptr<Card>card = this->drawCard();
    string outcome;
    printTurnDetails(m_turnIndex, player, *card);

    outcome = player.playCard(card);
    printTurnOutcome(outcome);

    m_turnIndex++;
}

void Mtmchkin::playRound()
{
    int i;

    printRoundStart();

    for (i = 0; i < ((int)this->m_players.size()); i++)
    {
        if (this->m_players[i]->isAlive())
            this->playTurn(*(this->m_players[i]));
    }

    printRoundEnd();

    printLeaderBoardMessage();

    vector<shared_ptr<Player>> leaderboard = this->getLeaderboard();
    for (int i = 0; i < (int)leaderboard.size(); i++)
        printLeaderBoardEntry(i + 1, *(leaderboard[i]));

    printBarrier();
}

bool Mtmchkin::isGameOver() const
{
    int i;
    bool any_alive = false;
    for (i = 0; i < (int)this->m_players.size(); i++)
    {
        if (this->m_players[i]->getLevel() == 10)
            return true;
        if (this->m_players[i]->isAlive())
            any_alive = true;
    }
    return !any_alive;
}

void Mtmchkin::play()
{
    printStartMessage();
    for (int i = 0; i < (int)this->m_players.size(); i++)
        printStartPlayerEntry(i + 1, *(this->m_players[i]));
    printBarrier();

    while (!isGameOver())
    {
        playRound();
    }

    printGameOver();

    shared_ptr<Player>player = this->getWinner();
    if (player == NULL)
        printNoWinners();
    else
        printWinner(*player);
}

vector<shared_ptr<Player>> Mtmchkin::getLeaderboard()
{
    int i, j;
    vector<shared_ptr<Player>> leaderboard;
    shared_ptr<Player> p;
    leaderboard.push_back(this->m_players[0]);
    for (i = 1; i < (int)this->m_players.size(); i++)
    {
        p = this->m_players[i];
        j = 0;
        while (j < (int)leaderboard.size() && leaderboard[j]->isGreaterThan(p))
            j++;
        leaderboard.insert(leaderboard.begin() + j, p);
    }
    return leaderboard;
}

shared_ptr<Player>Mtmchkin::getWinner()
{
    vector<shared_ptr<Player>> leaderboard = this->getLeaderboard();
    shared_ptr<Player>winner = leaderboard[0];
    if (winner->getLevel() == 10)
        return winner;
    else
        return NULL;
}
