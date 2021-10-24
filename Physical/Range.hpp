#ifndef RANGE_HPP_D6FC0B8A_0402_4031_B380_72C7C2D1D0DB
#define RANGE_HPP_D6FC0B8A_0402_4031_B380_72C7C2D1D0DB

#include <cstdint>

///////////////////////////////////////////////////////////////////////////////

namespace common
{

///////////////////////////////////////////////////////////////////////////////

namespace range
{

///////////////////////////////////////////////////////////////////////////////

template <typename Value_T>
bool is_well_formed( const Range<Value_T>& rng )
{
    return rng.high() >= rng.low();
}

///////////////////////////////////////////////////////////////////////////////

template <typename Value_T>
Value_T push_into_range( const Value_T& val, const Range<Value_T>& rng )
{
    if ( val < rng.low() )
    {
        return rng.low();
    }

    if ( val > rng.high() )
    {
        return rng.high();
    }

    return val;
}

///////////////////////////////////////////////////////////////////////////////

enum class compare_result : int8_t
{
    below,
    low_side_overlap,
    super_range,
    equal_range,
    sub_range,
    high_side_overlap,
    above
};

///////////////////////////////////////////////////////////////////////////////

template <typename Value_T>
compare_result compare( const Range<Value_T>& ref_range, const Range<Value_T>& target_range )
{
    if ( ref_range.high() <= target_range.low() )
    {
        return compare_result::below;
    }

    if ( ref_range.low() < target_range.low() && ref_range.high() < target_range.high() )
    {
        return compare_result::low_side_overlap;
    }

    if ( ref_range.low() >= target_range.low() && ref_range.high() < target_range.high() )
    {
        return compare_result::super_range;
    }

    if ( ref_range.low() < target_range.low() && ref_range.high() > target_range.high() )
    {
        return compare_result::sub_range;
    }

    if ( ref_range.low() > target_range.low() && ref_range.high() > target_range.high() )
    {
        return compare_result::high_side_overlap;
    }

    if ( ref_range.low() >= target_range.high() )
    {
        return compare_result::above;
    }

    return compare_result::equal_range;
}

///////////////////////////////////////////////////////////////////////////////

}   // namespace: range

///////////////////////////////////////////////////////////////////////////////

template <typename Value_T>
class Range
{
public:
    using Value_t = Value_T;

    Range( const Value_t& low, const Value_t& high )
        : m_low{ low }
        , m_high{ high }
    {}

    const Value_t& low() const { return m_low; }
    void set_low( const Value_t& low ) { m_low = low; }

    const Value_t& high() const { return m_high; }
    void set_high( const Value_t& high ) { m_high = high; }

    range::compare_result get_overlap( const Value_T& val ) const
    {
        if ( val < m_low )
        {
            return range::compare_result::below_range;
        }

        if ( val > m_high )
        {
            return range::compare_result::above_range;
        }

        return range::compare_result::in_range;
    }

    bool operator<( const Range<Value_T>& other ) const
    {
        return range::compare_result::below == range::compare( *this, other );
    }

private:
    Value_t m_low;
    Value_t m_high;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace: common

///////////////////////////////////////////////////////////////////////////////

#endif // RANGE_HPP_D6FC0B8A_0402_4031_B380_72C7C2D1D0DB

///////////////////////////////////////////////////////////////////////////////

