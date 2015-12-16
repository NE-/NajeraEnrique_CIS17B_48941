/*
 * File:    player.cpp
 * Author:  Enrique Najera
 * Purpose: Player properties
 * 16 December 2015
 */

// USER_LIBS
#include "player.h"

// Start constructor Player
Player::Player()
{
    // INIT sprite positions
    left     =  0;
    forward  = 32;
    right    = 64;
    backward = 96;
    frame = 0;

    // Set player image
    sheet_player = new QPixmap(":/img/images/player.png");
    setPixmap(sheet_player->copy(0, forward, 32, 32));

    // Position player in middle of screen
    setPos(256 / 2, 256/2);

    // INIT position
    posX = 256 / 2;
    posY = 256 / 2;

    // Create sounds
    snd_walk = new QMediaPlayer;
    snd_walk->setMedia(QUrl("qrc:/sound/sounds/SFX/footstep.mp3"));

}// End constructor Player

// Start method keyPressEvent
void Player::keyPressEvent(QKeyEvent *event)
{
    // Player movement
    if (event->key() == Qt::Key_Right)
    {
        // play walk sound
        if (snd_walk->state() == QMediaPlayer::PlayingState)
            snd_walk->setPosition(0);
        else if (snd_walk->state() == QMediaPlayer::StoppedState)
            snd_walk->play();

        pState = 'R';
        if (posX > -87)
        {
            frame++;
            posX-=5;
        }
        else
            pState = 'F'; // Idle
    }
    else if (event->key() == Qt::Key_Left)
    {
        // play walk sound
        if (snd_walk->state() == QMediaPlayer::PlayingState)
            snd_walk->setPosition(0);
        else if (snd_walk->state() == QMediaPlayer::StoppedState)
            snd_walk->play();

        pState = 'L';
        if (posX < 243)
        {
            frame++;
            posX+=5;
        }
        else
            pState = 'A'; // Idle
    }
    else if (event->key() == Qt::Key_Up)
    {
        // play walk sound
        if (snd_walk->state() == QMediaPlayer::PlayingState)
            snd_walk->setPosition(0);
        else if (snd_walk->state() == QMediaPlayer::StoppedState)
            snd_walk->play();

        pState = 'U';
        if (posY < 243)
        {
            frame++;
            posY+=5;
        }
        else
            pState = 'W'; // Idle
    }
    else if (event->key() == Qt::Key_Down)
    {
        // play walk sound
        if (snd_walk->state() == QMediaPlayer::PlayingState)
            snd_walk->setPosition(0);
        else if (snd_walk->state() == QMediaPlayer::StoppedState)
            snd_walk->play();

        pState = 'D';

        if (posY > -97)
        {
            frame++;
            posY-=5;
        }
        else
            pState = 'S'; // Idle
    }
    // Player Interaction
    else if (event->key() == Qt::Key_Z)
    {
        pState = 'I';
    }
    // In-Game Menu
    else if (event->key() == Qt::Key_X)
    {
        pState = 'M';

    }
}// End method keyPressEvent

// Start method keyReleaseEvent
void Player::keyReleaseEvent(QKeyEvent *event)
{
    // Sets player as idle
    if (event->key() == Qt::Key_Right)
    {
        pState = 'F';
    }
    else if (event->key() == Qt::Key_Left)
    {
        pState = 'A';
    }
    else if (event->key() == Qt::Key_Up)
    {
        pState = 'W';
    }
    else if (event->key() == Qt::Key_Down)
    {
        pState = 'S';
    }
}// End method keyReleaseEvent

// Start method collisions
void Player::collisions()
{
    /*****RIGHT*****/
    // -cupboard
    // --facing up
    if ((posX == 128 ||
         posX == 123 ||
         posX == 118 ||
         posX == 113 ||
         posX == 108 ||
         posX == 103) && posY >= 213 && (pState == 'U' || pState == 'W'))
    {
        posY = 213;
        facing = 'C';
    }
    // --facing right
    else if ((posY == 223 ||
              posY == 228 ||
              posY == 233 ||
              posY == 238 ||
              posY == 243)&& posX <= 138 && posX >= 43 && (pState == 'R' || pState == 'F'))
    {
        posX = 138;
        facing = 'X';
    }
    else
        facing = 'X';
    // end cupboard

    // -chair 1
    // --facing up
    if ((posX == 193 ||
         posX == 198 ||
         posX == 203 ||
         posX == 208 ||
         posX == 213 ||
         posX == 218)&& posY >= 183 && posY <=188 && (pState == 'U' || pState == 'W'))
    {
        posY = 183;
        facing = 'c';
    }
    // --facing down
    else if ((posX == 198 ||
              posX == 203 ||
              posX == 208 ||
              posX == 213 ||
              posX == 218)&& posY <= 208 && posY >=203 && (pState == 'D' || pState == 'S'))
         {
             posY = 208;
             facing = 'X';
         }
    // --facing right
    else if ((posY == 188 ||
              posY == 193 ||
              posY == 198 ||
              posY == 203) && posX <= 223 && posX >= 218 && (pState == 'R' || pState == 'F'))
    {
        posX = 223;
        facing = 'X';
    }
    // --facing left
    else if ((posY == 188 ||
              posY == 193 ||
              posY == 198 ||
              posY == 203) && posX >= 193 && posX <= 198 && (pState == 'L' || pState == 'A'))
    {
        posX = 193;
        facing = 'X';
    }
    // end chair 1

    // -chair 2
    // --facing up
    if ((posX == 128 ||
         posX == 133 ||
         posX == 138 ||
         posX == 143 ||
         posX == 148 ||
         posX == 153)&& posY >= 183 && posY <=188 && (pState == 'U' || pState == 'W'))
    {
        posY = 183;
        facing = 'c';
    }
    // --facing down
    else if ((posX == 133 ||
              posX == 138 ||
              posX == 143 ||
              posX == 148 ||
              posX == 153)&& posY <= 208 && posY >=203 && (pState == 'D' || pState == 'S'))
         {
             posY = 208;
             facing = 'X';
         }
    // --facing right
    else if ((posY == 188 ||
              posY == 193 ||
              posY == 198 ||
              posY == 203)&& posX <= 158 && posX >= 153 && (pState == 'R' || pState == 'F'))
    {
        posX = 158;
        facing = 'X';
    }
    // --facing left
    else if ((posY == 188 ||
              posY == 193 ||
              posY == 198 ||
              posY == 203)&& posX >= 128 && posX <= 133 && (pState == 'L' || pState == 'A'))
    {
        posX = 128;
        facing = 'X';
    }
    // end chair 2

    // -couch
    // --facing up
    if ((posX == 228 ||
         posX == 233 ||
         posX == 238 ||
         posX == 243)&& posY >= -2 && posY <= 3 && (pState == 'U' || pState == 'W'))
    {
        posY = -2;
        facing = 'X';
    }
    // --facing down
    else if ((posX == 228 ||
              posX == 233 ||
              posX == 238 ||
              posX == 243)&& posY <= 88 && posY >= 83 && (pState == 'D' || pState == 'S'))
    {
        posY = 88;
        facing = 'X';
    }
    // --facing left
    else if ((posY ==  3 ||
              posY ==  8 ||
              posY == 13 ||
              posY == 18 ||
              posY == 23 ||
              posY == 28 ||
              posY == 33 ||
              posY == 38 ||
              posY == 43 ||
              posY == 48 ||
              posY == 53 ||
              posY == 58 ||
              posY == 63 ||
              posY == 68 ||
              posY == 73 ||
              posY == 78 ||
              posY == 83)&& posX >= 223 && posX <= 228 && (pState == 'L' || pState == 'A'))
    {
        posX = 223;
        facing = 'Q';
    }
    // end couch

    // -table
    // --facing down
    if ((posX == 153 ||
         posX == 158 ||
         posX == 163 ||
         posX == 168 ||
         posX == 173 ||
         posX == 178 ||
         posX == 183 ||
         posX == 188 ||
         posX == 193)&& posY <= -82 && posY >= -87 && (pState == 'D' || pState == 'S'))
    {
        posY = -82;
        facing = 'T';
    }
    // --facing left
    else if ((posY == -87 ||
              posY == -92 ||
              posY == -97)&& posX >= 148 && posX <= 153 && (pState == 'L' || pState == 'A'))
    {
        posX = 148;
        facing = 'X';
    }
    // --facing right
    else if ((posY == -87 ||
              posY == -92 ||
              posY == -97)&& posX <= 198 && posX >= 193 && (pState == 'R' || pState == 'F'))
    {
        posX = 198;
        facing = 'X';
    }
    // end table

    // -plant
    // --facing right
    if ((posY == -72 ||
         posY == -77 ||
         posY == -82 ||
         posY == -87 ||
         posY == -92 ||
         posY == -97)&& posX <= 133 && posX >= 128 && (pState == 'R' || pState == 'F'))
    {
        posX = 133;
        facing = 'X';
    }
    // --facing down
    else if ((posX == 103 ||
              posX == 108 ||
              posX == 113 ||
              posX == 118 ||
              posX == 123 ||
              posX == 128)&& posY <= -67 && posY >= -72 && (pState == 'D' || pState == 'S'))
    {
        posY = -67;
        facing = 'p';
    }
    // end plant

}// End method collisions
