#ifndef RESULT_H
#define RESULT_H

#include <assert.h>

typedef enum Result {
  Ok = 0,
  OutOfMemErr,
  RangeErr,

  // should be last
  ResultCount
} Result;

static const char *const result_msgs[] = {
  [Ok] = "ok",
  [OutOfMemErr] = "out of memory!",
  [RangeErr] = "out of range!",
};

static_assert(
  sizeof(result_msgs) / sizeof(*result_msgs) == ResultCount,
  "Several results are not described!"
);

const char *const result_explain(Result result) { return result_msgs[result]; }

/* #define result_match(result, ...) \
   { \
     const Result error = (result); \
     switch (error) \
   } \
  ((void)0) */

#define unroll(result)                                                         \
  {                                                                            \
    const Result error = (result);                                             \
    switch (error) {                                                           \
    case Ok: break;                                                            \
    default: return error;                                                     \
    }                                                                          \
  }                                                                            \
  ((void)0)

#endif
