#pragma once

#include <cstddef>
#include <string_view>
#include <sstream>

#define LOAD_RESOURCE(RESOURCE) ([]() {                                             \
        extern const char _resource_##RESOURCE[];                                   \
        extern const size_t _resource_##RESOURCE##_len;                             \
        return std::string_view(_resource_##RESOURCE, _resource_##RESOURCE##_len);  \
    })()

#define LOAD_RESOURCE_STR(RESOURCE) ([]() {                     \
        auto resource = LOAD_RESOURCE(RESOURCE);                \
        return std::string(resource.data(), resource.size());   \
    })()

#define LOAD_RESOURCE_STREAM(RESOURCE) ([]() {  \
        auto str = LOAD_RESOURCE_STR(RESOURCE); \
        return std::istringstream(str);         \
    })()
