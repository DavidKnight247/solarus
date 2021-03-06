/*
 * Copyright (C) 2006-2015 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "solarus/AbilityInfo.h"
#include "solarus/lowlevel/Debug.h"

namespace Solarus {

namespace {

const std::map<Ability, std::string> ability_names = {
    { Ability::TUNIC, "tunic" },
    { Ability::SWORD, "sword" },
    { Ability::SWORD_KNOWLEDGE, "sword_knowledge" },
    { Ability::SHIELD, "shield" },
    { Ability::LIFT, "lift" },
    { Ability::SWIM, "swim" },
    { Ability::RUN, "run" },
    { Ability::DETECT_WEAK_WALLS, "detect_weak_walls" }
};

}  // Anonymous namespace.

namespace AbilityInfo {

/**
 * \brief Returns the ability values and their Lua name.
 * \return The name of each ability.
 */
const std::map<Ability, std::string>& get_ability_names() {
  return ability_names;
}

/**
 * \brief Returns the name of an ability.
 * \param type A ability value.
 * \return The corresponding name.
 */
const std::string& get_ability_name(Ability ability) {

  return ability_names.at(ability);
}

/**
 * \brief Returns the ability value with the given name.
 * \param ability_name The ability of an ability. It must exist.
 * \return The corresponding ability value.
 */
Ability get_ability_by_name(const std::string& ability_name) {

  for (const auto& kvp: ability_names) {
    if (kvp.second == ability_name) {
      return kvp.first;
    }
  }

  Debug::die(std::string("Unknown ability: ") + ability_name);
}

}

}
