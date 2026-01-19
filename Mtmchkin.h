
#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <exception>
#include <cctype>

#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Sorcerer.h"
#include "Players/Behavior.h"

#include "Cards/Card.h"
#include "Cards/Monster.h"
#include "Cards/Gang.h"
#include "Cards/Encounter.h"
#include "Cards/Event.h"

using namespace std;

bool validatePlayerName(string name);

class Mtmchkin
{
private:
    int m_turnIndex;
    deque<shared_ptr<Card>> m_deck;
    vector<shared_ptr<Player>> m_players;

    /**
     * Function to read a deck file and fill the deck queue with cards
     *
     * @param deckPath - path to the deck file
     *
     * @return - void
     *
     */
    void readDeckFile(const string &deckPath);

    /**
     * Function to read a players file and fill the players vector
     *
     * @param playersPath - path to the players file
     *
     * @return - void
     *
     */
    void readPlayersFile(const string &playersPath);

    /**
     * Function to draw a card from the top of the deck, return it and
     * place it to the bottom of the deck
     *
     * @return - a card from the top of the deck
     *
     */
    shared_ptr<Card>drawCard();

    /**
     * Function to play the turn for a given player
     *
     * @param player - the player whose turn it is
     *
     * @return - void
     *
     */
    void playTurn(Player &player);

    /**
     * Function to play a round of turns. Each alive player gets a turn
     * per round
     *
     * @return - void
     *
     */
    void playRound();

    /**
     * Function to check if the game is over or not.
     *
     * @return - true is game has ended else false
     *
     */
    bool isGameOver() const;

    /**
     * Function to sort the players into a ranking leaderboard
     * based on their stats
     *
     * @return - a vector of Player pointers sorted from highest
     * ranking to lowest
     *
     */
    vector<shared_ptr<Player>> getLeaderboard();

    /**
     * Function to find the winner of the game after the game has
     * ended
     *
     * @return - the player who has won. If there is no winner, NULL is
     * returned.
     *
     */
    shared_ptr<Player>getWinner();

public:
    /**
     * Constructor of Mtmchkin class
     *
     * @param deckPath - path to the deck file
     * @param playersPath - path to the players file
     *
     * @return - Mtmchkin object with the given deck and players
     *
     */
    Mtmchkin(const string &deckPath, const string &playersPath);
    
    /**
     * Plays the entire game
     *
     * @return - void
     */
    void play();
};

/**
 * Subclass of exception to cover the invalid players file
 */
class InvalidPlayersFileException : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid Players File";
    }
};

/**
 * Subclass of exception to cover the invalid cards file
 */
class InvalidCardsFileException : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid Cards File";
    }
};