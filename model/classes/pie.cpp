#include "pie.h"

std::vector<std::vector<std::string>> Pie::frames = {
    {"assets/pie/standing/left1.png", "assets/pie/standing/left2.png"},
    {"assets/pie/standing/right1.png", "assets/pie/standing/right2.png"},
    {"assets/pie/flying/left1.png", "assets/pie/flying/left2.png", "assets/pie/flying/left3.png", "assets/pie/flying/left4.png"},
    {"assets/pie/flying/right1.png", "assets/pie/flying/right2.png", "assets/pie/flying/right3.png", "assets/pie/flying/right4.png"}
};

std::vector<unsigned int> Pie::frameSpeeds = {10, 10, 5, 5};
