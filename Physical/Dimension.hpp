#pragma once

#include "api.h"

#include <string>

namespace common
{
namespace dimension
{

class PHYSICAL_API Dimension
{
public :
    Dimension() = default;
    ~Dimension() = default;

    virtual const char* name() const = 0;
};

class PHYSICAL_API Length : public Dimension
{
public :
    const char* name() const override { return "Length"; }
};

}
}