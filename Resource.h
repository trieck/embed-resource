#pragma once

#include <cstddef>
#include <string>
#include <sstream>

class Resource
{
public:
    Resource(const char* start, const size_t len) : resource_(start), len_(len)
    {}

    const char* const& data() const
    {
        return resource_;
    }

    const size_t& size() const
    {
        return len_;
    }

    const char* begin() const
    {
        return resource_;
    }

    const char* end() const
    {
        return resource_ + len_;
    }

    std::string toString()
    {
        return std::string(data(), size());
    }

    std::istringstream toStream()
    {
        return std::istringstream(toString());
    }

private:
    const char* resource_;
    const size_t len_;
};

#define LOAD_RESOURCE(RESOURCE) ([]() {                                     \
        extern const char _resource_##RESOURCE[];                           \
        extern const size_t _resource_##RESOURCE##_len;                     \
        return Resource(_resource_##RESOURCE, _resource_##RESOURCE##_len);  \
    })()

#define LOAD_RESOURCE_STR(RESOURCE) ([]() {         \
        auto resource = LOAD_RESOURCE(RESOURCE);    \
        return resource.toString();                 \
    })()

#define LOAD_RESOURCE_STREAM(RESOURCE) ([]() {      \
        auto resource = LOAD_RESOURCE(RESOURCE);    \
        return resource.toStream();                 \
    })()
