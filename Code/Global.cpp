#include "Global.hpp"

using namespace sf;
using namespace std;

string whiteString = "\033[0m";
string greenString = "\033[32m";
string redString = "\033[31m";

float screenWidth = 1600.f, screenHeight = screenWidth * 0.5625f;
RenderWindow window(VideoMode(screenWidth, screenHeight), "ExCusEee Me, pRiNcesS", Style::Close);
View mainView(FloatRect(screenWidth / 2, screenHeight / 2, 220, 220 * 0.5625f));
bool isGameRunning = true;
bool playable = true;
Time timeSinceLastFrame;
Time timeSinceLastFrameInputs;
bool hasGateKey = false;
bool isInPauseMenu = false;

//Additional Menu Variables
bool isInMenu = true;
Vector2i mousePosition;
bool hoverButtonPlay = false;
bool hoverButtonExit = false;
Font font;

//GUI Interaction
bool hoverButtonResume = false;
bool hoverButtonQuit = false;

Texture hpBarTexture;
shared_ptr<Sprite> hpBar = make_shared<Sprite>();
Vector2f inputMovement = Vector2f(0.f, 0.f);
int playerMoney = 0;
Texture playerKeyTexture;
shared_ptr<Sprite> playerKey = make_shared<Sprite>();
bool showHitbox = false;

Texture playerTextureFrontIdle;
Texture playerTextureFrontWalk;
Texture playerTextureBackIdle;
Texture playerTextureBackWalk;
Texture playerTextureSideIdle;
Texture playerTextureSideWalk;

//tiles
    //exterior
Texture grassTile1Texture;
Texture grassTile2Texture;
Texture grassWallDownTexture;
Texture grassWallSideTexture;
Texture grassWallDownEndTexture;
Texture grassWallTopTexture;
Texture grassWallTopEndTexture;
Texture grassWallCornerTexture;
Texture waterTileTexture;
Texture bridgeTexture;
Texture treeTexture;
Texture highGroundTile;
Texture doorExteriorTileTexture;
Texture potTexture;
//dungeon
Texture wallTileTexture;
Texture wallTileSideTexture;
Texture wallTileBackTexture;
Texture wallTileBackEndTexture;
Texture wallTileBackIntersectionTexture;
Texture wallTileMiddleTexture;
Texture wallTileMiddleEndTexture;
Texture wallTileIntersectionTexture;
Texture wallTileIntersectionSideTexture;
Texture floorTileTexture;
Texture doorTileLeftTexture;
Texture doorTileRightTexture;
Texture flagTileTexture;
Texture candleTexture;

Texture rubyTexture;
Texture swordTexture;
Texture axeTexture;
Texture daggerTexture;

//Menu Textures
Texture backgroundTexture;
Texture buttonPlayTexture;
Texture buttonPlayHoverTexture;
Texture buttonExitTexture;
Texture buttonExitHoverTexture;


//Menu Sprites
Sprite background;
Sprite buttonPlay;
Sprite buttonOptions;
Sprite buttonExit;

//GUI Sprites
Sprite pumpcoinPouch;
Sprite gateKey;
Sprite doorKey;

//GUI Texture
Texture pumpcoinPouchTexture;
Text pumpcoinText;
Texture gateKeyTexture;
Texture resumeButtonTexture;
Texture resumeButtonHoverTexture;
Texture quitButtonTexture;
Texture quitButtonHoverTexture;
Texture doorKeyTexture;
Text doorkeyText;

//Enemy Textures
Texture hunterTextureBot;
Texture hunterTextureTop;
Texture hunterTextureLeft;
Texture hunterTextureRight;

//Sounds
SoundBuffer pumpcoinCollectBuffer;
Sound pumpcoinCollectSFX;

void loadTextures() {
    font.setSmooth(false);
    playerTextureFrontIdle.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Front animations/spr_player_front_idle.png");
    playerTextureFrontWalk.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Front animations/spr_player_front_walk.png");
    playerTextureBackIdle.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Back animations/spr_player_back_idle.png");
    playerTextureBackWalk.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Back animations/spr_player_back_walk.png");
    playerTextureSideIdle.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Side animations/spr_player_right_idle.png");
    playerTextureSideWalk.loadFromFile("Images/Pixelarium - Playable Character - Free Version/Pack Content/Side animations/spr_player_right_walk.png");
    hpBarTexture.loadFromFile("Images/healthBar.png");

    grassTile1Texture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_tile_1.png");
    grassTile2Texture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_tile_2.png");
    grassWallDownTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_down.png");
    grassWallSideTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_side.png");
    grassWallDownEndTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_down_end.png");
    grassWallTopTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_top.png");
    grassWallTopEndTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_top_end.png");
    grassWallCornerTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/grass_wall_corner.png");
    waterTileTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/water_tile.png");
    bridgeTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/bridge.png");
    treeTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Vegetation/spr_tree1.png");

    highGroundTile.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/highGroundTile.png");
    doorExteriorTileTexture.loadFromFile("Images/32rogues/door_tile.png");
    potTexture.loadFromFile("Images/Dungeon Gathering Free Version/Vase Shine Anim.png");

    wallTileTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile.png");
    wallTileSideTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_side.png");
    wallTileBackTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_back.png");
    wallTileBackEndTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_back_end.png");
    wallTileBackIntersectionTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_back_intersection.png");
    wallTileMiddleTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_middle.png");
    wallTileMiddleEndTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_middle_end.png");
    wallTileIntersectionTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_intersection.png");
    wallTileIntersectionSideTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/wall_tile_intersection_side.png");
    floorTileTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/floor_tile.png");
    doorTileLeftTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/door_tile_left.png");
    doorTileRightTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/character and tileset/door_tile_right.png");
    flagTileTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/items and trap_animation/flag/flag_idle.png");
    candleTexture.loadFromFile("Images/2D Pixel Dungeon Asset Pack/items and trap_animation/torch/candlestick_2_idle.png");

    rubyTexture.loadFromFile("Images/Coin_Gems/ruby_red.png");
    swordTexture.loadFromFile("Images/textureepeee");
    axeTexture.loadFromFile("Images/textureaxez");
    daggerTexture.loadFromFile("Images/texturenigger");

    //Main Menu Textures
    backgroundTexture.loadFromFile("Images/mainmenu/background.png");
    buttonPlayTexture.loadFromFile("Images/mainmenu/buttons/play/buttonPlay.png");
    buttonPlayHoverTexture.loadFromFile("Images/mainmenu/buttons/play/buttonPlayHover.png");
    buttonExitTexture.loadFromFile("Images/mainmenu/buttons/exit/buttonExit.png");
    buttonExitHoverTexture.loadFromFile("Images/mainmenu/buttons/exit/buttonExitHover.png");

    //GUI Textures
    pumpcoinPouchTexture.loadFromFile("Images/GUI/pumpcoinPouchTexture.png");
    gateKeyTexture.loadFromFile("Images/GUI/gatekey.png");
    doorKeyTexture.loadFromFile("Images/GUI/doorkey.png");

    resumeButtonTexture.loadFromFile("Images/GUI/pausemenu/resume/resumeButton.png");
    resumeButtonHoverTexture.loadFromFile("Images/GUI/pausemenu/resume/resumeButtonHover.png");
    quitButtonTexture.loadFromFile("Images/GUI/pausemenu/quit/quitButton.png");
    quitButtonHoverTexture.loadFromFile("Images/GUI/pausemenu/quit/quitButtonHover.png");

    //Hunter Textures
    hunterTextureBot.loadFromFile("Images/free-slime-mobs-pixel-art-top-down-sprite-pack/PNG/Slime1/Walk/Slime_bot.png");
    hunterTextureTop.loadFromFile("Images/free-slime-mobs-pixel-art-top-down-sprite-pack/PNG/Slime1/Walk/Slime_top.png");
    hunterTextureRight.loadFromFile("Images/free-slime-mobs-pixel-art-top-down-sprite-pack/PNG/Slime1/Walk/Slime_right.png");
    hunterTextureLeft.loadFromFile("Images/free-slime-mobs-pixel-art-top-down-sprite-pack/PNG/Slime1/Walk/Slime_left.png");


}

void loadSound() {
    pumpcoinCollectBuffer.loadFromFile("Sounds/pumpcoin-collect.ogg");
    pumpcoinCollectSFX.setBuffer(pumpcoinCollectBuffer);
}

void continueAnimation(shared_ptr<Sprite> sprite) {
    const Texture* texture = sprite->getTexture();
    if (sprite->getTextureRect().left >= texture->getSize().x - sprite->getTextureRect().width) {
        sprite->setTextureRect(IntRect(0, 0, sprite->getTextureRect().width, sprite->getTextureRect().height));
    }
    else {
        IntRect rect = sprite->getTextureRect();
        rect.left += sprite->getTextureRect().width;
        sprite->setTextureRect(rect);
    }
}

Vector2f normalize(Vector2f value)
{
    float baseX = 1.f;
    float baseY = 1.f;
    if (int(value.x) < 0) {
        baseX = -1.f;
    }
    else if (int(value.x) == 0) {
        baseX = 0;
    }
    if (int(value.y) < 0) {
        baseY = -1.f;
    }
    else if (int(value.y) == 0) {
        baseY = 0;
    }
    if (abs(value.x) > abs(value.y)) {
        return Vector2f(baseX, baseY - baseY * abs(value.y / value.x));
    }
    else if (abs(value.x) < abs(value.y)) {
        return Vector2f(baseX - baseX * abs(value.x / value.y), baseY);
    }
    else {
        return Vector2f(baseX, baseY);
    }
}