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

//Additional Menu Variables
bool isInMenu = true;
Vector2i mousePosition;
bool hoverButtonPlay = false;
bool hoverButtonExit = false;



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

Texture grassTile1Texture;
Texture grassTile2Texture;
Texture grassWallDownTexture;
Texture grassWallSideTexture;
Texture grassWallDownEndTexture;
Texture grassWallTopTexture;
Texture grassWallTopEndTexture;
Texture waterTileTexture;
Texture bridgeTexture;
Texture treeTexture;
Texture highGroundTile;
Texture doorExteriorTileTecture;
Texture potTexture;

Texture rubyTexture;

//Menu Textures
Texture backgroundTexture;
Texture buttonPlayTexture;
Texture buttonPlayHoverTexture;
Texture buttonExitTexture;
Texture buttonExitHoverTexture;


Sprite background;
Sprite buttonPlay;
Sprite buttonOptions;
Sprite buttonExit;


void loadTextures() {
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
    waterTileTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/water_tile.png");
    bridgeTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/bridge.png");
    treeTexture.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Vegetation/spr_tree1.png");

    highGroundTile.loadFromFile("Images/Pixelarium - GrassLands - Free Version/Pack content/Sprites/Tileset/highGroundTile.png");
    doorExteriorTileTecture.loadFromFile("Images/32rogues/door_tile.png");
    potTexture.loadFromFile("Images/Dungeon Gathering Free Version/Vase Shine Anim.png");
    rubyTexture.loadFromFile("Images/Coin_Gems/ruby_red.png");

    //Main Menu Textures
    backgroundTexture.loadFromFile("Images/mainmenu/background.png");
    buttonPlayTexture.loadFromFile("Images/mainmenu/buttons/play/buttonPlay.png");
    buttonPlayHoverTexture.loadFromFile("Images/mainmenu/buttons/play/buttonPlayHover.png");
    buttonExitTexture.loadFromFile("Images/mainmenu/buttons/exit/buttonExit.png");
    buttonExitHoverTexture.loadFromFile("Images/mainmenu/buttons/exit/buttonExitHover.png");

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