#include "Lair.h"


Lair::Lair() {
    Act             = ActID::ACT_1;
    PositionData[0] = 0;
    PositionData[1] = 0;
    PositionData[2] = 0;
    Type            = LairType::LAIR_ONE_BY_ONE;
    Enemy           = EnemyType::NO_ENEMY;
    NbEnemies       = 0;
    SpawnRate       = 0;
    Orientation     = 0;
}

Lair::~Lair() {}

Lair& Lair::operator= (const Lair& OtherLair) {
    if (this != &OtherLair) {
        Act             = OtherLair.Act;
        PositionData[0] = OtherLair.PositionData[0];
        PositionData[1] = OtherLair.PositionData[1];
        PositionData[2] = OtherLair.PositionData[2];
        Type            = OtherLair.Type;
        Enemy           = OtherLair.Enemy;
        NbEnemies       = OtherLair.NbEnemies;
        SpawnRate       = OtherLair.SpawnRate;
        Orientation     = OtherLair.Orientation;
    }
    return *this;
}

bool Lair::NoFishLairPosition() {
    /* Some monster lairs should not have fish enemies, otherwise it would crash the game */
    return ( (PositionData[0] == 0x2E && PositionData[1] == 0x23) ||
             (PositionData[0] == 0x2F && PositionData[1] == 0x14 && PositionData[2] == 0x08) ||
             (PositionData[0] == 0x2F && PositionData[1] == 0x24 && PositionData[2] == 0x0F) ||
             (PositionData[0] == 0x2F && PositionData[1] == 0x1A && PositionData[2] == 0x17) ||
             (PositionData[0] == 0x2F && PositionData[1] == 0x20 && PositionData[2] == 0x18) ||
             (PositionData[0] == 0x30 && PositionData[1] == 0x16 && PositionData[2] == 0x11) ||
             (PositionData[0] == 0x30 && PositionData[1] == 0x0C && PositionData[2] == 0x24) ||
             (PositionData[0] == 0x30 && PositionData[1] == 0x2D && PositionData[2] == 0x11) ||
             (PositionData[0] == 0x31 && PositionData[1] == 0x04 && PositionData[2] == 0x11) ||
             (PositionData[0] == 0x31 && PositionData[1] == 0x39 && PositionData[2] == 0x2B) ||
             (PositionData[0] == 0x31 && PositionData[1] == 0x3B && PositionData[2] == 0x1A) ||
             (PositionData[0] == 0x31 && PositionData[1] == 0x06 && PositionData[2] == 0x20) );
}

bool Lair::NoMetalLairPosition() {
    /* Some monster lairs are assumed to be beatable without Zantetsu Sword */
    return ( (PositionData[0] == 0x56 && PositionData[1] == 0x19 && PositionData[2] == 0x23) ||
             (PositionData[0] == 0x56 && PositionData[1] == 0x02 && PositionData[2] == 0x2E) ||
             (PositionData[0] == 0x56 && PositionData[1] == 0x1D && PositionData[2] == 0x11) ||
             (PositionData[0] == 0x56 && PositionData[1] == 0x2B && PositionData[2] == 0x23) ||
             (PositionData[0] == 0x58 && PositionData[1] == 0x20 && PositionData[2] == 0x0A) );
}

bool Lair::NoGhostLairPosition() {
    /* Some monster lairs are assumed to be beatable without Spirit Sword */
    return ( (PositionData[0] == 0x66 && PositionData[1] == 0x0C && PositionData[2] == 0x07) ||
             (PositionData[0] == 0x66 && PositionData[1] == 0x29 && PositionData[2] == 0x09) ||
             (PositionData[0] == 0x66 && PositionData[1] == 0x09 && PositionData[2] == 0x14) );
}

bool Lair::MustBeMetalLairPosition() {
    /* These lairs are supposed to have metal enemies, requiring the Zantetsu Sword to defeat */
    return ( (PositionData[0] == 0x56 && PositionData[1] == 0x39 && PositionData[2] == 0x35) ||
             (PositionData[0] == 0x58 && PositionData[1] == 0x32 && PositionData[2] == 0x2E) );
}

bool Lair::MustBeGhostLairPosition() {
    /* This lair is supposed to have ghost enemies, requiring the Spirit Sword to defeat */
    return (PositionData[0] == 0x66 && PositionData[1] == 0x2A && PositionData[2] == 0x1E);
}

bool Lair::MustNotRandomizeLairPosition() {
    /* These lairs should not be randomized (until I find a better way to deal with them) */
    return ( (PositionData[0] == 0x20 && PositionData[1] == 0x08 && PositionData[2] == 0x27) ||
             (PositionData[0] == 0x3E && PositionData[1] == 0x0E && PositionData[2] == 0x26) ||
             (PositionData[0] == 0x3E && PositionData[1] == 0x17 && PositionData[2] == 0x39) ||
             (PositionData[0] == 0x3F && PositionData[1] == 0x0A && PositionData[2] == 0x27) ||
             (PositionData[0] == 0x56 && PositionData[1] == 0x2D && PositionData[2] == 0x31) ||
             (PositionData[0] == 0x58 && PositionData[1] == 0x37 && PositionData[2] == 0x34) );
}

bool Lair::MustNotBeUpwardsLairPosition() {
    /* This lair cannot have enemies oriented upwards */
    return (PositionData[0] == 0x1B && PositionData[1] == 0x25 && PositionData[2] == 0x05);
}
