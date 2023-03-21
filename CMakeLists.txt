cmake_minimum_required(VERSION 3.22)
project(crc CXX)

set(CMAKE_CXX_STANDARD 11)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(
		-pedantic -Wall -Wextra
		-Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization
		-Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
		-Wmissing-include-dirs -Wold-style-cast -Wredundant-decls -Wshadow
		-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
		-Wstrict-overflow -Wsuggest-override -Wswitch-default -Wundef

		#-Werror
	)
else()
	message(WARNING "Unknown compiler - not turning on warnings")
endif()



list(APPEND CRC_ALGORITHMS
	crc_3_gsm
	crc_3_rohc
	crc_4_g_704
	crc_4_interlaken
	crc_5_epc_c1g2
	crc_5_g_704
	crc_5_usb
	crc_6_cdma2000_a
	crc_6_cdma2000_b
	crc_6_darc
	crc_6_g_704
	crc_6_gsm
	crc_7_mmc
	crc_7_rohc
	crc_7_umts
	crc_8_autosar
	crc_8_bluetooth
	crc_8_cdma2000
	crc_8_darc
	crc_8_dvb_s2
	crc_8_gsm_a
	crc_8_gsm_b
	crc_8_hitag
	crc_8_i_432_1
	crc_8_i_code
	crc_8_lte
	crc_8_maxim_dow
	crc_8_mifare_mad
	crc_8_nrsc_5
	crc_8_opensafety
	crc_8_rohc
	crc_8_sae_j1850
	crc_8_smbus
	crc_8_tech_3250
	crc_8_wcdma
	crc_10_atm
	crc_10_cdma2000
	crc_10_gsm
	crc_11_flexray
	crc_11_umts
	crc_12_cdma2000
	crc_12_dect
	crc_12_gsm
	crc_12_umts
	crc_13_bbc
	crc_14_darc
	crc_14_gsm
	crc_15_can
	crc_15_mpt1327
	crc_16_arc
	crc_16_cdma2000
	crc_16_cms
	crc_16_dds_110
	crc_16_dect_r
	crc_16_dect_x
	crc_16_dnp
	crc_16_en_13757
	crc_16_genibus
	crc_16_gsm
	crc_16_ibm_3740
	crc_16_ibm_sdlc
	crc_16_iso_iec_14443_3_a
	crc_16_kermit
	crc_16_lj1200
	crc_16_m17
	crc_16_maxim_dow
	crc_16_mcrf4xx
	crc_16_modbus
	crc_16_nrsc_5
	crc_16_opensafety_a
	crc_16_opensafety_b
	crc_16_profibus
	crc_16_riello
	crc_16_spi_fujitsu
	crc_16_t10_dif
	crc_16_teledisk
	crc_16_tms37157
	crc_16_umts
	crc_16_usb
	crc_16_xmodem
	crc_17_can_fd
	crc_21_can_fd
	crc_24_ble
	crc_24_flexray_a
	crc_24_flexray_b
	crc_24_interlaken
	crc_24_lte_a
	crc_24_lte_b
	crc_24_openpgp
	crc_24_os_9
	crc_30_cdma
	crc_31_philips
	crc_32_aixm
	crc_32_autosar
	crc_32_base91_d
	crc_32_bzip2
	crc_32_cd_rom_edc
	crc_32_cksum
	crc_32_iscsi
	crc_32_iso_hdlc
	crc_32_jamcrc
	crc_32_mef
	crc_32_mpeg_2
	crc_32_xfer
	crc_40_gsm
	crc_64_ecma_182
	crc_64_go_iso
	crc_64_ms
	crc_64_we
	crc_64_xz
)

option(CRC_BUILD_COMBINED "build combined library for all algorithms" ON)
foreach(i ${CRC_ALGORITHMS})
	option(CRC_BUILD_${i} "build library for ${i}" OFF)
endforeach()




foreach(i ${CRC_ALGORITHMS})
	set(table_src tables/src/${i}.cpp)

	list(APPEND CRC_DECLARATIONS
		${CMAKE_CURRENT_SOURCE_DIR}/declarations/${i}.inl
	)
	list(APPEND CRC_TABLES_INCLUDE
		tables/include/crc/${i}.h
	)
	list(APPEND CRC_TABLES_SRC
		${table_src}
	)
	if(CRC_BUILD_${i})
		add_library(${i} SHARED
			${table_src}
		)
		target_include_directories(${i} PUBLIC
			include
			${CMAKE_CURRENT_BINARY_DIR}/tables/include
		)
	endif()
endforeach()

if(CRC_BUILD_COMBINED)
	add_library(crc SHARED
		${CRC_TABLES_SRC}
	)

	target_include_directories(crc PUBLIC
		include
		${CMAKE_CURRENT_BINARY_DIR}/tables/include
	)
endif()


add_executable(gen_tables
	gen_tables.cpp
)

target_include_directories(gen_tables PUBLIC
	include
	declarations
)



if(CRC_BUILD_COMBINED)
	add_executable(test
		test.cpp
	)

	target_link_libraries(test
		crc
	)
endif()



add_custom_command(
	OUTPUT ${CRC_TABLES_INCLUDE} ${CRC_TABLES_SRC}
	COMMAND mkdir -p tables/include/crc
	COMMAND mkdir -p tables/src
	COMMAND gen_tables ${CMAKE_CURRENT_SOURCE_DIR}/declarations tables
	DEPENDS gen_tables ${CRC_DECLARATIONS}
)


