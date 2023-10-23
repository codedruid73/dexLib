link_libraries(
    CD1::DexLib
)

# ItemTest
add_qt_test(ItemTest "tst_item.cpp")

# ServiceTest
add_qt_test(DexServiceTest "tst_dexservice.cpp")
