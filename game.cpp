#include "game.hpp"
#include <string>

#include "audio/mp3-stream.hpp"
#include "assets.hpp"

using namespace blit;

int money = 0;
int upgradeCost = 10;
int moneyPerClick = 1;

MP3Stream stream;

///////////////////////////////////////////////////////////////////////////
//
// init()
//
// setup your game here
//
void init() {
    set_screen_mode(ScreenMode::hires);

  // Files should be encoded as 22050Hz mono, but stereo and/or 44100Hz also work.
  // (The output is still 22050Hz/mono)

  // It's also possible to load directly from the SD card.
  File::add_buffer_file("example.mp3", click_sound, click_sound_length);

  // Pass false for do_duration_calc if you don't need the duration.
  // (it requires decoding the entire file, which takes a while if reading from the SD card)
  stream.load("ClickSound.mp3", true);

}

///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount if milliseconds elapsed since the start of your game
//
void render(uint32_t time) {
    screen.clear();

    // Fill the background with white
    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(0, 0, 320, 240));

    // Draw the black header bar
    screen.pen = Pen(0, 0, 0);
    screen.rectangle(Rect(0, 0, 320, 14));

    // Draw the header text in white
    screen.pen = Pen(255, 255, 255);
    screen.text("Clicker", minimal_font, Point(5, 5));

    // Draw the rest of the text in black
    screen.pen = Pen(0, 0, 0);
    screen.text("Money:", minimal_font, Point(100, 65));
    screen.text(std::to_string(money), minimal_font, Point(180, 65));

    screen.text("Press A to click!", minimal_font, Point(85, 120));
    screen.text("Press X to upgrade clicks!", minimal_font, Point(85, 150));

    screen.text("Per click:", minimal_font, Point(85, 165));
    screen.text(std::to_string(moneyPerClick), minimal_font, Point(180, 165));

    screen.text("Upgrade cost:", minimal_font, Point(85, 180));
    screen.text(std::to_string(upgradeCost), minimal_font, Point(180, 180));
}

///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount if milliseconds elapsed since the start of your game
//
void update(uint32_t time) {
    if (buttons.pressed & Button::A) {
        money += moneyPerClick;
        stream.play(0);
    } 
    if (buttons.pressed & Button::X) {
        //upgrade
        if (money >= upgradeCost) {
            money -= upgradeCost;
            moneyPerClick += 1; 
            upgradeCost = upgradeCost * 2;
        }
    }
}