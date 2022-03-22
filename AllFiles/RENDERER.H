#include "model.h"
#include "const.h"
#include "raster.h"
#include <osbind.h>

void renderPlayer(const struct Player *Player,UINT16 *base);

void renderCrystal(const struct Crystal *crystal,UINT16 *base);

void renderScore(const struct Score *score,UINT16 *base);

void renderTimer(const struct TimeRemaining *timeLeft, UINT16 *base);

void renderPlatform(const struct Platform platform[],UINT16 *base);

void render(const struct Model *model, UINT16 *base);
