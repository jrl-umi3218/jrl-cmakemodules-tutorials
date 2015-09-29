/* YAML example taken from:
 * https://code.google.com/p/yaml-cpp/wiki/HowToParseADocument
 * and (badly) adapted to the newest API*/
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <string>
#include <vector>


static const std::string yaml_data = R"(- name: Ogre
  position: [0, 5, 0]
  powers:
    - name: Club
      damage: 10
    - name: Fist
      damage: 8
- name: Dragon
  position: [1, 0, 10]
  powers:
    - name: Fire Breath
      damage: 25
    - name: Claws
      damage: 15
- name: Wizard
  position: [5, -3, 0]
  powers:
    - name: Acid Rain
      damage: 50
    - name: Staff
      damage: 3
)";

// our data types
struct Vec3 {
   float x, y, z;
};

struct Power {
   std::string name;
   int damage;
};

struct Monster {
   std::string name;
   Vec3 position;
   std::vector <Power> powers;
};

// now the extraction operators for these types
void operator >> (const YAML::Node& node, Vec3& v) {
  v.x = node[0].as<float>();
  v.y = node[1].as<float>();
  v.z = node[2].as<float>();
}

void operator >> (const YAML::Node& node, Power& power) {
  power.name = node["name"].as<std::string>();
  power.damage = node["damage"].as<int>();
}

void operator >> (const YAML::Node& node, Monster& monster) {
  monster.name = node["name"].as<std::string>();
   node["position"] >> monster.position;
   const YAML::Node& powers = node["powers"];
   for(unsigned i=0;i<powers.size();i++) {
      Power power;
      powers[i] >> power;
      monster.powers.push_back(power);
   }
}

int main()
{
  YAML::Node doc = YAML::Load(yaml_data.c_str());
  for(unsigned i=0;i<doc.size();i++) {
     Monster monster;
     doc[i] >> monster;
     std::cout << monster.name << std::endl;
  }
  return 0;
}
