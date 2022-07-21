#include "config.h"

#include <stdio.h>
#include <log.h>
#include <hidapi.h>
#include <unistd.h>


int main() {
    int res;
    hid_device *sensor_handle;
    unsigned char buf[256];
    wchar_t vendor_string[256];

    log_info("Starting %s-%s", app_name, app_version);
    log_info("Author: %s - %s", app_author, app_website);

    log_info("Attempting seteid(0) to access USB devices...");
    res = seteuid(0);
    if (res != 0) {
        log_error("Could not become root - has this executable been marked with setuid permissions?");
        return 1;
    }

    res = hid_init();
    sensor_handle = hid_open(pd_sensor_vid, pd_sensor_pid, NULL);

    if (sensor_handle == NULL) {
        log_error("Could not open presence detect sensor. Is it plugged in?");
        return 1;
    }

    while (true) {
        res = hid_read(sensor_handle, buf, 256);
        if (res != 2)
            continue;
        if (buf[1] == 0x01) {
            log_info("Carbon-based life form detected");
        } else {
            log_info("Carbon-based life form disappeared");
        }
    }

    return 0;
}
