#ifndef RESULT_H
#define RESULT_H

#include <assert.h>

typedef enum Result {
  Ok = 0,
  UnknownErr,
  OutOfMemErr,
  RangeErr,

  ResultCount,  // should be last
} Result;

static char const *const result_msgs[] = {
  [Ok] = "ok",
  [UnknownErr] = "unknown!",
  [OutOfMemErr] = "out of memory!",
  [RangeErr] = "out of range!",
};

// clang-format off
static_assert(sizeof(result_msgs) / sizeof(*result_msgs) == ResultCount, "Several results are not described!");
// clang-format on

#define explain(result) (result_msgs[result])

/* #define result_match(result, ...) \
   { \
      Result const error = (result); \
     switch (error) \
   } \
  ((void)0) */

#define unroll(result)                                                         \
  {                                                                            \
    Result const error = (result);                                             \
    switch (error) {                                                           \
    case Ok: break;                                                            \
    default: return error;                                                     \
    }                                                                          \
  }                                                                            \
  ((void)0)

#endif
