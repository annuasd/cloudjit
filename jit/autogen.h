#pragma once

#define CJIT_EXPAND(x) x
#define CJIT_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12,     \
                        _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, \
                        _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, \
                        _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, \
                        _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, \
                        _57, _58, _59, _60, _61, _62, _63, _64, NAME, ...)     \
   NAME



#define CJIT_PASTE(...)                                                       \
   CJIT_EXPAND(CJIT_GET_MACRO(                                               \
     __VA_ARGS__, CJIT_PASTE64, CJIT_PASTE63, CJIT_PASTE62, CJIT_PASTE61,  \
     CJIT_PASTE60, CJIT_PASTE59, CJIT_PASTE58, CJIT_PASTE57,               \
     CJIT_PASTE56, CJIT_PASTE55, CJIT_PASTE54, CJIT_PASTE53,               \
     CJIT_PASTE52, CJIT_PASTE51, CJIT_PASTE50, CJIT_PASTE49,               \
     CJIT_PASTE48, CJIT_PASTE47, CJIT_PASTE46, CJIT_PASTE45,               \
     CJIT_PASTE44, CJIT_PASTE43, CJIT_PASTE42, CJIT_PASTE41,               \
     CJIT_PASTE40, CJIT_PASTE39, CJIT_PASTE38, CJIT_PASTE37,               \
     CJIT_PASTE36, CJIT_PASTE35, CJIT_PASTE34, CJIT_PASTE33,               \
     CJIT_PASTE32, CJIT_PASTE31, CJIT_PASTE30, CJIT_PASTE29,               \
     CJIT_PASTE28, CJIT_PASTE27, CJIT_PASTE26, CJIT_PASTE25,               \
     CJIT_PASTE24, CJIT_PASTE23, CJIT_PASTE22, CJIT_PASTE21,               \
     CJIT_PASTE20, CJIT_PASTE19, CJIT_PASTE18, CJIT_PASTE17,               \
     CJIT_PASTE16, CJIT_PASTE15, CJIT_PASTE14, CJIT_PASTE13,               \
     CJIT_PASTE12, CJIT_PASTE11, CJIT_PASTE10, CJIT_PASTE9, CJIT_PASTE8,  \
     CJIT_PASTE7, CJIT_PASTE6, CJIT_PASTE5, CJIT_PASTE4, CJIT_PASTE3,     \
     CJIT_BASE_PASTE2, CJIT_PASTE1)(__VA_ARGS__))

#define CJIT_BASE_PASTE2(func, v1) func(v1)
#define CJIT_PASTE2(func, v1)     func(v1),
#define CJIT_PASTE3(func, v1, v2) CJIT_PASTE2(func, v1)  CJIT_BASE_PASTE2(func, v2)
#define CJIT_PASTE4(func, v1, v2, v3)                                         \
   CJIT_PASTE2(func, v1) CJIT_PASTE3(func, v2, v3)
#define CJIT_PASTE5(func, v1, v2, v3, v4)                                     \
   CJIT_PASTE2(func, v1) CJIT_PASTE4(func, v2, v3, v4)
#define CJIT_PASTE6(func, v1, v2, v3, v4, v5)                                 \
   CJIT_PASTE2(func, v1) CJIT_PASTE5(func, v2, v3, v4, v5)
#define CJIT_PASTE7(func, v1, v2, v3, v4, v5, v6)                             \
   CJIT_PASTE2(func, v1) CJIT_PASTE6(func, v2, v3, v4, v5, v6)
#define CJIT_PASTE8(func, v1, v2, v3, v4, v5, v6, v7)                         \
   CJIT_PASTE2(func, v1) CJIT_PASTE7(func, v2, v3, v4, v5, v6, v7)
#define CJIT_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8)                     \
   CJIT_PASTE2(func, v1) CJIT_PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define CJIT_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9)                \
   CJIT_PASTE2(func, v1) CJIT_PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
#define CJIT_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)           \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE10(func, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#define CJIT_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)      \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE11(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#define CJIT_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE12(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define CJIT_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13)                                                     \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE13(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#define CJIT_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14)                                                \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE14(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define CJIT_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15)                                           \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE15(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15)
#define CJIT_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16)                                      \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE16(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16)
#define CJIT_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17)                                 \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE17(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17)
#define CJIT_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18)                            \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE18(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18)
#define CJIT_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE19(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19)
#define CJIT_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20)                  \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE20(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20)
#define CJIT_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21)             \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE21(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21)
#define CJIT_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22)        \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE22(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22)
#define CJIT_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE23(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23)
#define CJIT_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24)                                                     \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE24(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24)
#define CJIT_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25)                                                \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE25(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25)
#define CJIT_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26)                                           \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE26(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26)
#define CJIT_PASTE28(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27)                                      \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE27(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27)
#define CJIT_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28)                                 \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE28(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28)
#define CJIT_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29)                            \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE29(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29)
#define CJIT_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE30(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30)
#define CJIT_PASTE32(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31)                  \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE31(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31)
#define CJIT_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32)             \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE32(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32)
#define CJIT_PASTE34(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)        \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE33(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33)
#define CJIT_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE34(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define CJIT_PASTE36(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35)                                                     \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE35(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35)
#define CJIT_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36)                                                \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE36(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define CJIT_PASTE38(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37)                                           \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE37(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37)
#define CJIT_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38)                                      \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE38(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38)
#define CJIT_PASTE40(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39)                                 \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE39(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39)
#define CJIT_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40)                            \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE40(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40)
#define CJIT_PASTE42(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE41(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41)
#define CJIT_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42)                  \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE42(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42)
#define CJIT_PASTE44(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43)             \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE43(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43)
#define CJIT_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)        \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE44(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44)
#define CJIT_PASTE46(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE45(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45)
#define CJIT_PASTE47(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE46(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define CJIT_PASTE48(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47)                                                \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE47(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)
#define CJIT_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48)                                           \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE48(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define CJIT_PASTE50(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49)                                      \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE49(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)
#define CJIT_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50)                                 \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE50(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50)
#define CJIT_PASTE52(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51)                            \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE51(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51)
#define CJIT_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE52(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52)
#define CJIT_PASTE54(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53)                  \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE53(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53)
#define CJIT_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53, v54)             \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE54(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54)
#define CJIT_PASTE56(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53, v54, v55)        \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE55(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55)
#define CJIT_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE56(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56)
#define CJIT_PASTE58(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE57(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57)
#define CJIT_PASTE59(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)                  \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE58(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58)
#define CJIT_PASTE60(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59)             \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE59(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58, v59)
#define CJIT_PASTE61(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)        \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE60(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)
#define CJIT_PASTE62(                                                         \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)   \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE61(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)
#define CJIT_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56,   \
                      v57, v58, v59, v60, v61, v62)                            \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE62(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
                 v62)
#define CJIT_PASTE64(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, \
                      v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,   \
                      v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,   \
                      v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45,   \
                      v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56,   \
                      v57, v58, v59, v60, v61, v62, v63)                       \
   CJIT_PASTE2(func, v1)                                                      \
   CJIT_PASTE63(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,     \
                 v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25,   \
                 v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37,   \
                 v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49,   \
                 v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
                 v62, v63)

#define CJIT_ARG2_PASTE(...)                                                  \
   CJIT_EXPAND(CJIT_GET_MACRO(                                               \
     __VA_ARGS__, CJIT_PLACEHOLDER, CJIT_ARGS62_PASTE31, CJIT_PLACEHOLDER,  \
     CJIT_ARGS60_PASTE30, CJIT_PLACEHOLDER, CJIT_ARGS58_PASTE29,            \
     CJIT_PLACEHOLDER, CJIT_ARGS56_PASTE28, CJIT_PLACEHOLDER,               \
     CJIT_ARGS54_PASTE27, CJIT_PLACEHOLDER, CJIT_ARGS52_PASTE26,            \
     CJIT_PLACEHOLDER, CJIT_ARGS50_PASTE25, CJIT_PLACEHOLDER,               \
     CJIT_ARGS48_PASTE24, CJIT_PLACEHOLDER, CJIT_ARGS46_PASTE23,            \
     CJIT_PLACEHOLDER, CJIT_ARGS44_PASTE22, CJIT_PLACEHOLDER,               \
     CJIT_ARGS42_PASTE21, CJIT_PLACEHOLDER, CJIT_ARGS40_PASTE20,            \
     CJIT_PLACEHOLDER, CJIT_ARGS38_PASTE19, CJIT_PLACEHOLDER,               \
     CJIT_ARGS36_PASTE18, CJIT_PLACEHOLDER, CJIT_ARGS34_PASTE17,            \
     CJIT_PLACEHOLDER, CJIT_ARGS32_PASTE16, CJIT_PLACEHOLDER,               \
     CJIT_ARGS30_PASTE15, CJIT_PLACEHOLDER, CJIT_ARGS28_PASTE14,            \
     CJIT_PLACEHOLDER, CJIT_ARGS26_PASTE13, CJIT_PLACEHOLDER,               \
     CJIT_ARGS24_PASTE12, CJIT_PLACEHOLDER, CJIT_ARGS22_PASTE11,            \
     CJIT_PLACEHOLDER, CJIT_ARGS20_PASTE10, CJIT_PLACEHOLDER,               \
     CJIT_ARGS18_PASTE9, CJIT_PLACEHOLDER, CJIT_ARGS16_PASTE8,              \
     CJIT_PLACEHOLDER, CJIT_ARGS14_PASTE7, CJIT_PLACEHOLDER,                \
     CJIT_ARGS12_PASTE6, CJIT_PLACEHOLDER, CJIT_ARGS10_PASTE5,              \
     CJIT_PLACEHOLDER, CJIT_ARGS8_PASTE4, CJIT_PLACEHOLDER,                 \
     CJIT_ARGS6_PASTE3, CJIT_PLACEHOLDER, CJIT_ARGS4_PASTE2,                \
     CJIT_PLACEHOLDER, CJIT_ARGS2_PASTE1, CJIT_PLACEHOLDER,                 \
     CJIT_PLACEHOLDER)(__VA_ARGS__))

#define CJIT_ARGS2_PASTE1(func, v1, v2) v2 arg##v1 = func<v2>(argv[v1], #v2);
#define CJIT_ARGS4_PASTE2(func, v1, v2, v3, v4)                               \
   CJIT_ARGS2_PASTE1(func, v1, v2) CJIT_ARGS2_PASTE1(func, v3, v4)
#define CJIT_ARGS6_PASTE3(func, v1, v2, v3, v4, v5, v6)                       \
   CJIT_ARGS4_PASTE2(func, v1, v2, v3, v4) CJIT_ARGS2_PASTE1(func, v5, v6)
#define CJIT_ARGS8_PASTE4(func, v1, v2, v3, v4, v5, v6, v7, v8)               \
   CJIT_ARGS6_PASTE3(func, v1, v2, v3, v4, v5, v6)                            \
   CJIT_ARGS2_PASTE1(func, v7, v8)
#define CJIT_ARGS10_PASTE5(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)     \
   CJIT_ARGS8_PASTE4(func, v1, v2, v3, v4, v5, v6, v7, v8)                    \
   CJIT_ARGS2_PASTE1(func, v9, v10)
#define CJIT_ARGS12_PASTE6(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12)                                          \
   CJIT_ARGS10_PASTE5(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)          \
   func(v11, v12)
#define CJIT_ARGS14_PASTE7(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14)                                \
   CJIT_ARGS12_PASTE6(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12)                                                    \
   func(v13, v14)
#define CJIT_ARGS16_PASTE8(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14, v15, v16)                      \
   CJIT_ARGS14_PASTE7(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14)                                          \
   func(v15, v16)
#define CJIT_ARGS18_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14, v15, v16, v17, v18)            \
   CJIT_ARGS16_PASTE8(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14, v15, v16)                                \
   func(v17, v18)
#define CJIT_ARGS20_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) \
   CJIT_ARGS18_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14, v15, v16, v17, v18)                      \
   func(v19, v20)
#define CJIT_ARGS22_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22)                                         \
   CJIT_ARGS20_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20)           \
   func(v21, v22)
#define CJIT_ARGS24_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24)                               \
   CJIT_ARGS22_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22) \
   func(v23, v24)
#define CJIT_ARGS26_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26)                     \
   CJIT_ARGS24_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24)                                              \
   func(v25, v26)
#define CJIT_ARGS28_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28)           \
   CJIT_ARGS26_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26)                                    \
   func(v27, v28)
#define CJIT_ARGS30_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30) \
   CJIT_ARGS28_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28)                          \
   func(v29, v30)
#define CJIT_ARGS32_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32)                                         \
   CJIT_ARGS30_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30)                \
   func(v31, v32)
#define CJIT_ARGS34_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34)                               \
   CJIT_ARGS32_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)      \
   func(v33, v34)
#define CJIT_ARGS36_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36)                     \
   CJIT_ARGS34_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34)                                                   \
   func(v35, v36)
#define CJIT_ARGS38_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38)           \
   CJIT_ARGS36_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36)                                         \
   func(v37, v38)
#define CJIT_ARGS40_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40) \
   CJIT_ARGS38_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38)                               \
   func(v39, v40)
#define CJIT_ARGS42_PASTE21(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)                       \
   CJIT_ARGS40_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40)                     \
   func(v41, v42)
#define CJIT_ARGS44_PASTE22(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)             \
   CJIT_ARGS42_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42)           \
   func(v43, v44)
#define CJIT_ARGS46_PASTE23(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)   \
   CJIT_ARGS44_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44) \
   func(v45, v46)
#define CJIT_ARGS48_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, \
                             v41, v42, v43, v44, v45, v46, v47, v48)           \
   CJIT_ARGS46_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46)                                              \
   func(v47, v48)
#define CJIT_ARGS50_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, \
                             v41, v42, v43, v44, v45, v46, v47, v48, v49, v50) \
   CJIT_ARGS48_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48)                                    \
   func(v49, v50)
#define CJIT_ARGS52_PASTE26(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52)                                                \
   CJIT_ARGS50_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50)                          \
   func(v51, v52)
#define CJIT_ARGS54_PASTE27(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54)                                      \
   CJIT_ARGS52_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52)                \
   func(v53, v54)
#define CJIT_ARGS56_PASTE28(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)                            \
   CJIT_ARGS54_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)      \
   func(v55, v56)
#define CJIT_ARGS58_PASTE29(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)                  \
   CJIT_ARGS56_PASTE28(                                                       \
     func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,   \
     v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,     \
     v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,     \
     v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)          \
   func(v57, v58)
#define CJIT_ARGS60_PASTE30(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)        \
   CJIT_ARGS58_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                        v56, v57, v58)                                         \
   func(v59, v60)
#define CJIT_ARGS62_PASTE31(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
  v62)                                                                         \
   CJIT_ARGS60_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                        v56, v57, v58, v59, v60)                               \
   func(v61, v62)


