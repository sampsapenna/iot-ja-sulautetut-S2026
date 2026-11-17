# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_2/iot-base-repo-example/pico-sdk/tools/pioasm")
  file(MAKE_DIRECTORY "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_2/iot-base-repo-example/pico-sdk/tools/pioasm")
endif()
file(MAKE_DIRECTORY
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pioasm"
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm"
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/tmp"
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src"
  "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/g_home/sampsa/Opetusmateriaalit/IoT_ja_sulautetut/Luentoesimerkit_SV2026/luento_3/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
