
add_definitions(
    " -std=c++17"
    " -Wall"
    " -Wextra"
    " -Wno-override-init"
    " -Wno-unused-parameter"
    " -Wno-sign-compare"
    " -Wno-pointer-sign"
    " -Wno-null-pointer-arithmetic"
)

set(CMAKE_C_FLAGS
        "${CMAKE_C_FLAGS} \
         -fsanitize=address \
         -fsanitize=undefined \
         -fsanitize-recover=all \
         -fno-omit-frame-pointer \
         -fno-stack-protector"
    )
add_executable(set set.cpp )
add_executable(multiset multiset.cpp )

