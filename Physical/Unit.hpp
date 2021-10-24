#pragma once

#include "api.h"
#include "Dimension.hpp"

#include <cstdint>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////

namespace common
{

///////////////////////////////////////////////////////////////////////////////

namespace
{

template<int8_t EXP>
struct Selector
{
    static constexpr int value = ( EXP < 0 ? -1 : (EXP > 0 ? 1 : 0));
};

template<int8_t EXP, int SELECT = 0xFFFFFFFF>
struct StaticExponentEvaluator {};

/// <summary>
/// Evaluates a power of 10 at compile time (for a positive exponent).
/// </summary>
template<int8_t EXP>
struct StaticExponentEvaluator<EXP, Selector<EXP>::value>
{
    static constexpr double value = 10 * StaticExponentEvaluator<EXP - 1>::value;
};

/// <summary>
/// Evaluates a power of 10 at compile time (for a negative exponent).
/// </summary>
template<int8_t EXP, std::enable_if_t<( EXP < 0 ), bool> = true>
struct StaticExponentEvaluator
{
    static constexpr double value = StaticExponentEvaluator<EXP + 1>::value / 10.0;
};

template<int8_t EXP, std::enable_if_t<( EXP == 0 ), bool> = true>
struct StaticExponentEvaluator
{
    static constexpr double value = 1.0;
};

}

///////////////////////////////////////////////////////////////////////////////

template <int8_t EXPONENT>
struct Prefix
{
    enum { __is_prefix_type };

    static constexpr auto exponent = EXPONENT;
};

///////////////////////////////////////////////////////////////////////////////

using Yocto = Prefix<-24>;
static constexpr Yocto yocto{};

using Zepto = Prefix<-21>;
static constexpr auto zepto = Zepto{};

using Atto = Prefix<-18>;
static constexpr auto atto = Atto{};

using Femto = Prefix<-15>;
static constexpr auto femto = Femto{};

using Pico = Prefix<-12>;
static constexpr auto pico = Pico{};

using Nano = Prefix<-9>;
static constexpr auto nano = Nano{};

using Micro = Prefix<-6>;
static constexpr auto micro = Micro{};

using Milli = Prefix<-3>;
static constexpr auto milli = Milli{};

using Centi = Prefix<-2>;
static constexpr auto centi = Centi{};

using Deci = Prefix<-1>;
static constexpr auto deci = Deci{};

using Deca = Prefix<1>;
static constexpr auto deca = Deca{};

using Hecto = Prefix<2>;
static constexpr auto hecto = Hecto{};

using Kilo = Prefix<3>;
static constexpr auto kilo = Kilo{};

using Mega = Prefix<6>;
static constexpr auto mega = Mega{};

using Giga = Prefix<9>;
static constexpr auto giga = Giga{};

using Tera = Prefix<12>;
static constexpr auto tera = Tera{};

using Peta = Prefix<15>;
static constexpr auto peta = Peta{};

using Exa = Prefix<18>;
static constexpr auto exa = Exa{};

using Zetta = Prefix<21>;
static constexpr auto zetta = Zetta{};

using Yotta = Prefix<24>;
static constexpr auto yotta = Yotta{};

///////////////////////////////////////////////////////////////////////////////

template <int8_t EXPONENT, int8_t MASS, int8_t LENGTH, int8_t TIME, int8_t CHARGE, int8_t TEMPERATURE, int8_t NUMBER, int8_t LUM_INT>
struct PHYSICAL_API Unit
{
    enum { __is_unit_type };

    static constexpr auto exponent = EXPONENT;

    static constexpr auto mass = MASS;
    static constexpr auto length = LENGTH;
    static constexpr auto time = TIME;
    static constexpr auto charge = CHARGE;
    static constexpr auto temperature = TEMPERATURE;
    static constexpr auto number = NUMBER;
    static constexpr auto luminous_intensity = LUM_INT;
};

///////////////////////////////////////////////////////////////////////////////

template <int8_t EXPONENT, int8_t MASS, int8_t LENGTH, int8_t TIME, int8_t CHARGE, int8_t TEMPERATURE, int8_t NUMBER, int8_t LUM_INT>
struct PHYSICAL_API SiUnit : public Unit<EXPONENT, MASS, LENGTH, TIME, CHARGE, TEMPERATURE, NUMBER, LUM_INT>
{
    /// <summary>
    /// All SI units have a factor of 1.
    /// </summary>
    static constexpr double factor = 1.0;

    /// <summary>
    /// All SI units have a zero offset.
    /// </summary>
    static constexpr double offset = 0.0;
};

///////////////////////////////////////////////////////////////////////////////

template< typename Prefix_T, typename Unit_T>
constexpr typename std::enable_if<
    Prefix_T::__is_prefix_type && Unit_T::__is_unit_type,
    Unit<
        Unit_T::exponent + Prefix_T::exponent,
        Unit_T::mass,
        Unit_T::length,
        Unit_T::time,
        Unit_T::charge,
        Unit_T::temperature,
        Unit_T::number,
        Unit_T::luminous_intensity
    >
>::type operator*(const Prefix_T&, const Unit_T&)
{
    return Unit<
        Unit_T::exponent + Prefix_T::exponent,
        Unit_T::mass,
        Unit_T::length,
        Unit_T::time,
        Unit_T::charge,
        Unit_T::temperature,
        Unit_T::number,
        Unit_T::luminous_intensity
    >{};
}

///////////////////////////////////////////////////////////////////////////////

template <typename Unit1_T, typename Unit2_T>
constexpr typename std::enable_if<
    Unit1_T::__is_unit_type&& Unit2_T::__is_unit_type,
    Unit<
    Unit1_T::exponent + Unit2_T::exponent,
    Unit1_T::mass + Unit2_T::mass,
    Unit1_T::length + Unit2_T::length,
    Unit1_T::time + Unit2_T::time,
    Unit1_T::charge + Unit2_T::charge,
    Unit1_T::temperature + Unit2_T::temperature,
    Unit1_T::number + Unit2_T::number,
    Unit1_T::luminous_intensity + Unit2_T::luminous_intensity
    >
>::type operator*( const Unit1_T& u1, const Unit2_T& u2 )
{
    return Unit<
        Unit1_T::exponent + Unit2_T::exponent,
        Unit1_T::mass + Unit2_T::mass,
        Unit1_T::length + Unit2_T::length,
        Unit1_T::time + Unit2_T::time,
        Unit1_T::charge + Unit2_T::charge,
        Unit1_T::temperature + Unit2_T::temperature,
        Unit1_T::number + Unit2_T::number,
        Unit1_T::luminous_intensity + Unit2_T::luminous_intensity
    >{};
}

///////////////////////////////////////////////////////////////////////////////

template <typename Unit1_T, typename Unit2_T>
constexpr typename std::enable_if<
    Unit1_T::__is_unit_type&& Unit2_T::__is_unit_type,
    Unit<
    Unit1_T::exponent - Unit2_T::exponent,
    Unit1_T::mass - Unit2_T::mass,
    Unit1_T::length - Unit2_T::length,
    Unit1_T::time - Unit2_T::time,
    Unit1_T::charge - Unit2_T::charge,
    Unit1_T::temperature - Unit2_T::temperature,
    Unit1_T::number - Unit2_T::number,
    Unit1_T::luminous_intensity - Unit2_T::luminous_intensity
    >
>::type operator/( const Unit1_T& u1, const Unit2_T& u2 )
{
    return Unit<
        Unit1_T::exponent - Unit2_T::exponent,
        Unit1_T::mass - Unit2_T::mass,
        Unit1_T::length - Unit2_T::length,
        Unit1_T::time - Unit2_T::time,
        Unit1_T::charge - Unit2_T::charge,
        Unit1_T::temperature - Unit2_T::temperature,
        Unit1_T::number - Unit2_T::number,
        Unit1_T::luminous_intensity - Unit2_T::luminous_intensity
    >{};
}

///////////////////////////////////////////////////////////////////////////////

namespace unit
{

template< typename FromUnit_T, typename ToUnit_T>
double transform( double val )
{
    static_assert( From_T::mass == To_T::mass, "Cannot convert between units with different dimensions" );
    static_assert( From_T::length == To_T::length, "Cannot convert between units with different dimensions" );
    static_assert( From_T::time == To_T::time, "Cannot convert between units with different dimensions" );
    static_assert( From_T::charge == To_T::charge, "Cannot convert between units with different dimensions" );
    static_assert( From_T::temperature == To_T::temperature, "Cannot convert between units with different dimensions" );
    static_assert( From_T::number == To_T::number, "Cannot convert between units with different dimensions" );
    static_assert( From_T::luminous_intensity == To_T::luminous_intensity, "Cannot convert between units with different dimensions" );

    constexpr factor = From_T::factor * StaticExponentEvaluator<From_T::exponent>::value / ( To_T::factor * StaticExponentEvaluator<To_T::exponent>::value );
    constexpr offset = From_T::offset * StaticExponentEvaluator<From_T::exponent>::value / ( To_T::factor * StaticExponentEvaluator<To_T::exponent>::value )
        - To_T::offset / StaticExponentEvaluator<To_T::exponent>::value;
    return offset + val * factor
}

} // namespace: unit

///////////////////////////////////////////////////////////////////////////////

template <typename Unit_T>
class PHYSICAL_API Quantity
{
public:
    using Unit_t = Unit_T;

    Quantity( double val ) : m_value{ val } {}

    template <typename OutputUnit_T>
    double in() const
    {
        return  unit::transform<Unit_t, OutputUnit_T>( m_value );
    }

private:
    double m_value;
};

///////////////////////////////////////////////////////////////////////////////

template <typename Value_T, typename Unit_T>
typename std::enable_if<std::is_arithmetic_v<Value_T>, Quantity<Unit_T>>::type operator*( const Value_T& val, const Unit_T& )
{
    return Quantity<Unit_T>(val);
}

}
