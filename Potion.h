//
// Created by regal on 9/9/25.
//

#ifndef FIGHTMONSTERS_POTION_H
#define FIGHTMONSTERS_POTION_H

#include <string>
#include <array>

namespace Potion
{
    static inline constexpr int EffectHealthSmall{2};
    static inline constexpr int EffectHealthMedium{2};
    static inline constexpr int EffectHealthLarge{5};

    static inline constexpr int EffectStrengthSmall{1};
    static inline constexpr int EffectStrengthMedium{1};
    static inline constexpr int EffectStrengthLarge{1};

    static inline constexpr int EffectPoisonSmall{1};
    static inline constexpr int EffectPoisonMedium{1};
    static inline constexpr int EffectPoisonLarge{1};

    class Potion
    {
    public:
        enum Type
        {
            health,
            strength,
            poison,
            max_types,
        };

        enum Size
        {
            small,
            medium,
            large,
            max_sizes,
        };

        static constexpr std::array<std::string_view, max_types> typeNames{"health", "strength", "poison"};
        static constexpr std::array<std::string_view, max_types> sizeNames{"small", "medium", "large"};
        static_assert(std::size(typeNames) == max_types);
        static_assert(std::size(sizeNames) == max_sizes);

        static constexpr std::array<Type, max_types> types{health, strength, poison};
        static constexpr std::array<Size, max_sizes> sizes{small, medium, large};
        static_assert(std::size(types) == max_types);
        static_assert(std::size(sizes) == max_sizes);


        explicit Potion(const Type potion, const Size size)
            :m_potionType(potion), m_size(size)
        {}

        [[nodiscard]] Type getPotionType() const {return m_potionType;}
        [[nodiscard]] Size getPotionSize() const {return m_size;}

        static Potion getRandomPotion();

    private:
        Type m_potionType{};
        Size m_size{};
    };
}

#endif //FIGHTMONSTERS_POTION_H