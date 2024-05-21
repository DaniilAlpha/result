#ifndef RESULT_H
#define RESULT_H

#include <assert.h>

typedef enum Result {
    Ok = 0,
    UnknownErr,
    OutOfMemErr,
    RangeErr,
    HashCollisionErr,

    FileUnavailableErr,
    FileReadingErr,
    FileWritingErr,

    FormatErr,
    ArgErr,
    StateErr,

    ResultCount,  // should be last
} Result;

static char const *const result_msgs[] = {
    [Ok] = "ok",
    [UnknownErr] = "unknown!",
    [OutOfMemErr] = "out of memory!",
    [RangeErr] = "out of range!",
    [HashCollisionErr] = "hash colision!",

    [FileUnavailableErr] = "file unavailable!",
    [FileReadingErr] = "file reading failed!",
    [FileWritingErr] = "file writing failed!",

    [FormatErr] = "invalid format!",
    [ArgErr] = "invalid argument!",
    [StateErr] = "invalid state!"
};

// clang-format off
static_assert(sizeof(result_msgs) / sizeof(*result_msgs) == ResultCount, "Several results are not described!");
// clang-format on

#define explain(result) (result_msgs[result])

#define unroll(result, ...)                                                    \
    {                                                                          \
        Result const error = (result);                                         \
        switch (error) {                                                       \
        case Ok: break;                                                        \
        default: __VA_ARGS__ return error;                                     \
        }                                                                      \
    }                                                                          \
    ((void)0)

#endif
