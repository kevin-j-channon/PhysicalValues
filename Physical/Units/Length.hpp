#pragma once

#include "../Unit.hpp"

///////////////////////////////////////////////////////////////////////////////

namespace common
{

///////////////////////////////////////////////////////////////////////////////

namespace unit
{

///////////////////////////////////////////////////////////////////////////////

//
// Metric Units
//

using Metre = SiUnit<0, 0, 1, 0, 0, 0, 0, 0>;
using Metres = Metre;
constexpr Metre metre{};

constexpr SiUnit<-24, 0, 1, 0, 0, 0, 0, 0> yoctometre = yocto * metre;
using YoctoMetre = decltype( yoctometre );
using YoctoMetres = YoctoMetre;

constexpr auto zeptometre = zepto * metre;
using ZeptoMetre = decltype( zeptometre );
using ZeptoMetres = ZeptoMetre;

constexpr auto attometre = atto * metre;
using AttoMetre = decltype( attometre );
using AttoMetres = AttoMetre;

constexpr auto femtometre = femto * metre;
using FemtoMetre = decltype( femtometre );
using FemtoMetres = FemtoMetre;

constexpr auto picoometre = pico * metre;
using PicoMetre = decltype( picometre );
using PicoMetres = PicoMetre;

constexpr auto nanometre = nano * metre;
using NanoMetre = decltype( nanometre );
using NanoMetres = NanoMetre;

constexpr auto micrometre = micro * metre;
using MicroMetre = decltype( micrometre );
using MicroMetres = MicroMetre;

constexpr auto millmetre = milli * metre;
using MilliMetre = decltype( millimetre );
using MilliMetres = MilliMetre;

constexpr auto centimetre = centi * metre;
using CentiMetre = decltype( centimetre );
using CentiMetres = CentiMetre;

constexpr auto decimetre = deci * metre;
using DeciMetre = decltype( decimetre );
using DeciMetres = DeciMetre;

constexpr auto decametre = deca * metre;
using DecaMetre = decltype( decametre );
using DecaMetres = DecaMetre;

constexpr auto hectometre = hecto * metre;
using HectoMetre = decltype( hectometre );
using HectoMetres = HectoMetre;

constexpr auto kilometre = kilo * metre;
using KiloMetre = decltype( kilometre );
using KiloMetres = KiloMetre;

constexpr auto megametre = mega * metre;
using MegaMetre = decltype( megametre );
using MegaMetres = MegaMetre;

constexpr auto gigametre = giga * metre;
using GigaMetre = decltype( gigametre );
using GigaMetres = GigaMetre;

constexpr auto terametre = tera * metre;
using TeraMetre = decltype( terametre );
using TeraMetres = TeraMetre;

constexpr auto petametre = peta * metre;
using PetaMetre = decltype( petametre );
using PetaMetres = PetaMetre;

constexpr auto exametre = exa * metre;
using ExaMetre = decltype( exametre );
using ExaMetres = ExaMetre;

constexpr auto zettametre = zetta * metre;
using ZettaMetre = decltype( zettametre );
using ZettaMetres = ZettaMetre;

constexpr auto yottametre = yotta * metre;
using YottaMetre = decltype( yottametre );
using YottaMetres = YottaMetre;

///////////////////////////////////////////////////////////////////////////////

//
// Imperial Units
//

///////////////////////////////////////////////////////////////////////////////

struct PHYSICAL_API Inch : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    /// <summary>
    /// An inch is 0.0254 metres, so its factor is 0.0254.
    /// </summary>
    static constexpr double factor = 0.0254;

    static constexpr double offset = 0.0;
};

using Inches = Inch;
constexpr auto inch = Inch{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A thou is a thousandth of an inch (so, a milli-inch).
/// </summary>
constexpr auto thou = milli * inch;
using Thou = decltype( thou );

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A Barleycorn is a third of an inch.
/// </summary>
struct PHYSICAL_API Barleycorn : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = Inch::factor / 3.0;
    static constexpr double offset = 0.0;
};

using Barleycorns = Barleycorn;
constexpr auto barleycorn = Barleycorn{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A hand is 4 inches.
/// </summary>
struct PHYSICAL_API Hand : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 4 * Inch::factor;
    static constexpr double offset = 0.0;
};

using Hands = Hand;
constexpr auto hand = Hand{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A foot is 12 inches.
/// </summary>
struct PHYSICAL_API Foot : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 12 * Inch::factor;
    static constexpr double offset = 0.0;
};

using Feet = Foot;
constexpr auto foot = Foot{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A yard is 3 feet.
/// </summary>
struct PHYSICAL_API Yard : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 3 * Foot::factor;
    static constexpr double offset = 0.0;
};

using Yards = Yard;
constexpr auto yard = Yard{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A chain is 22 yards.
/// </summary>
struct PHYSICAL_API Chain : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 22 * Yard::factor;
    static constexpr double offset = 0.0;
};

using Chains = Chain;
constexpr auto chain = Chain{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A furlong is 10 chains.
/// </summary>
struct PHYSICAL_API Furlong : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 10 * Chain::factor;
    static constexpr double offset = 0.0;
};

using Furlongs = Furlong;
constexpr auto furlong = Furlong{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A mile is 8 furlongs
/// </summary>
struct PHYSICAL_API Mile : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 8 * Furlong::factor;
    static constexpr double offset = 0.0;
};

using Miles = Mile;
constexpr auto mile = Mile{};

///////////////////////////////////////////////////////////////////////////////

/// <summary>
/// A league is 3 miles.
/// </summary>
struct PHYSICAL_API League : public Unit<0, 0, 1, 0, 0, 0, 0, 0>
{
    static constexpr double factor = 3 * Mile::factor;
    static constexpr double offset = 0.0;
};

using Leagues = League;
constexpr auto league = League{};

///////////////////////////////////////////////////////////////////////////////

} // namespace: unit
} // namespace: common

///////////////////////////////////////////////////////////////////////////////
