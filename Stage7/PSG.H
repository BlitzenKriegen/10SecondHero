#include <osbind.h>
#include "const.h"

void write_psg(int reg, UINT8 val);

UINT8 read_psg(int reg);

void set_tone(int channel, int tuning);

void enable_channel(int channel, int tone_on, int noise_on);

void set_volume(int channel, int volume);

void stop_sound();