//
// Created by friedkiwi on 21/07/22.
//

#ifndef PDDRIVER_CONFIG_H
#define PDDRIVER_CONFIG_H

static const char * app_name = "pddriver";
static const char * app_version = "0.1";
static const char * app_author = "Yvan Janssens";
static const char * app_website = "https://wiki.hackerspace.gent/Spacebar";
static const int    pd_sensor_vid = 0x0bf8;
static const int    pd_sensor_pid = 0x101a;
static const char * mouse_move_cmd = "DISPLAY=:0 xdotool mousemove_relative --polar 0 2";

#endif //PDDRIVER_CONFIG_H
