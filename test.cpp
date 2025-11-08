#include <crc/crc_3_gsm.h>
#include <crc/crc_3_rohc.h>
#include <crc/crc_4_g_704.h>
#include <crc/crc_4_interlaken.h>
#include <crc/crc_5_epc_c1g2.h>
#include <crc/crc_5_g_704.h>
#include <crc/crc_5_usb.h>
#include <crc/crc_6_cdma2000_a.h>
#include <crc/crc_6_cdma2000_b.h>
#include <crc/crc_6_darc.h>
#include <crc/crc_6_g_704.h>
#include <crc/crc_6_gsm.h>
#include <crc/crc_7_mmc.h>
#include <crc/crc_7_rohc.h>
#include <crc/crc_7_umts.h>
#include <crc/crc_8_autosar.h>
#include <crc/crc_8_bluetooth.h>
#include <crc/crc_8_cdma2000.h>
#include <crc/crc_8_darc.h>
#include <crc/crc_8_dvb_s2.h>
#include <crc/crc_8_gsm_a.h>
#include <crc/crc_8_gsm_b.h>
#include <crc/crc_8_hitag.h>
#include <crc/crc_8_i_432_1.h>
#include <crc/crc_8_i_code.h>
#include <crc/crc_8_lte.h>
#include <crc/crc_8_maxim_dow.h>
#include <crc/crc_8_mifare_mad.h>
#include <crc/crc_8_nrsc_5.h>
#include <crc/crc_8_opensafety.h>
#include <crc/crc_8_rohc.h>
#include <crc/crc_8_sae_j1850.h>
#include <crc/crc_8_smbus.h>
#include <crc/crc_8_tech_3250.h>
#include <crc/crc_8_wcdma.h>
#include <crc/crc_10_atm.h>
#include <crc/crc_10_cdma2000.h>
#include <crc/crc_10_gsm.h>
#include <crc/crc_11_flexray.h>
#include <crc/crc_11_umts.h>
#include <crc/crc_12_cdma2000.h>
#include <crc/crc_12_dect.h>
#include <crc/crc_12_gsm.h>
#include <crc/crc_12_umts.h>
#include <crc/crc_13_bbc.h>
#include <crc/crc_14_darc.h>
#include <crc/crc_14_gsm.h>
#include <crc/crc_15_can.h>
#include <crc/crc_15_mpt1327.h>
#include <crc/crc_16_arc.h>
#include <crc/crc_16_cdma2000.h>
#include <crc/crc_16_cms.h>
#include <crc/crc_16_dds_110.h>
#include <crc/crc_16_dect_r.h>
#include <crc/crc_16_dect_x.h>
#include <crc/crc_16_dnp.h>
#include <crc/crc_16_en_13757.h>
#include <crc/crc_16_genibus.h>
#include <crc/crc_16_gsm.h>
#include <crc/crc_16_ibm_3740.h>
#include <crc/crc_16_ibm_sdlc.h>
#include <crc/crc_16_iso_iec_14443_3_a.h>
#include <crc/crc_16_kermit.h>
#include <crc/crc_16_lj1200.h>
#include <crc/crc_16_m17.h>
#include <crc/crc_16_maxim_dow.h>
#include <crc/crc_16_mcrf4xx.h>
#include <crc/crc_16_modbus.h>
#include <crc/crc_16_nrsc_5.h>
#include <crc/crc_16_opensafety_a.h>
#include <crc/crc_16_opensafety_b.h>
#include <crc/crc_16_profibus.h>
#include <crc/crc_16_riello.h>
#include <crc/crc_16_spi_fujitsu.h>
#include <crc/crc_16_t10_dif.h>
#include <crc/crc_16_teledisk.h>
#include <crc/crc_16_tms37157.h>
#include <crc/crc_16_umts.h>
#include <crc/crc_16_usb.h>
#include <crc/crc_16_xmodem.h>
#include <crc/crc_17_can_fd.h>
#include <crc/crc_21_can_fd.h>
#include <crc/crc_24_ble.h>
#include <crc/crc_24_flexray_a.h>
#include <crc/crc_24_flexray_b.h>
#include <crc/crc_24_interlaken.h>
#include <crc/crc_24_lte_a.h>
#include <crc/crc_24_lte_b.h>
#include <crc/crc_24_openpgp.h>
#include <crc/crc_24_os_9.h>
#include <crc/crc_30_cdma.h>
#include <crc/crc_31_philips.h>
#include <crc/crc_32_aixm.h>
#include <crc/crc_32_autosar.h>
#include <crc/crc_32_base91_d.h>
#include <crc/crc_32_bzip2.h>
#include <crc/crc_32_cd_rom_edc.h>
#include <crc/crc_32_cksum.h>
#include <crc/crc_32_iso_hdlc.h>
#include <crc/crc_32_iscsi.h>
#include <crc/crc_32_jamcrc.h>
#include <crc/crc_32_mef.h>
#include <crc/crc_32_mpeg_2.h>
#include <crc/crc_32_xfer.h>
#include <crc/crc_40_gsm.h>
#include <crc/crc_64_ecma_182.h>
#include <crc/crc_64_go_iso.h>
#include <crc/crc_64_ms.h>
#include <crc/crc_64_nvme.h>
#include <crc/crc_64_redis.h>
#include <crc/crc_64_we.h>
#include <crc/crc_64_xz.h>

#include <iostream>



template<class C>
void check(typename C::R expected){
	const std::string name = C::name;
	const std::string check_string = "123456789";
	const auto check_1 = C::calc(check_string.c_str(), check_string.length());
	const auto check_2 = C::compute(check_string.c_str(), check_string.length());

	if(check_1 == expected && check_2 == expected){
		std::cout << "[" << name << "] " << "0x" << std::hex << static_cast<uint64_t>(expected) << std::dec << " ok" << std::endl;
	}else{
		if(check_1 != expected){
			std::cout << "[" << name << "] " << "direct calculation is 0x" << std::hex << static_cast<uint64_t>(check_1) << std::dec << std::endl;
		}
		if(check_2 != expected){
			std::cout << "[" << name << "] " << "table calculation is 0x" << std::hex << static_cast<uint64_t>(check_2) << std::dec << std::endl;
		}
	}
}


int main(int /*argc*/, char **/*argv*/){
	check<CRC_3_GSM>(0x4);
	check<CRC_3_ROHC>(0x6);
	check<CRC_4_G_704>(0x7);
	check<CRC_4_INTERLAKEN>(0xb);
	check<CRC_5_EPC_C1G2>(0x0);
	check<CRC_5_G_704>(0x07);
	check<CRC_5_USB>(0x19);
	check<CRC_6_CDMA2000_A>(0x0d);
	check<CRC_6_CDMA2000_B>(0x3b);
	check<CRC_6_DARC>(0x26);
	check<CRC_6_G_704>(0x06);
	check<CRC_6_GSM>(0x13);
	check<CRC_7_MMC>(0x75);
	check<CRC_7_ROHC>(0x53);
	check<CRC_7_UMTS>(0x61);
	check<CRC_8_AUTOSAR>(0xdf);
	check<CRC_8_BLUETOOTH>(0x26);
	check<CRC_8_CDMA2000>(0xda);
	check<CRC_8_DARC>(0x15);
	check<CRC_8_DVB_S2>(0xbc);
	check<CRC_8_GSM_A>(0x37);
	check<CRC_8_GSM_B>(0x94);
	check<CRC_8_HITAG>(0xb4);
	check<CRC_8_I_432_1>(0xa1);
	check<CRC_8_I_CODE>(0x7e);
	check<CRC_8_LTE>(0xea);
	check<CRC_8_MAXIM_DOW>(0xa1);
	check<CRC_8_MIFARE_MAD>(0x99);
	check<CRC_8_NRSC_5>(0xf7);
	check<CRC_8_OPENSAFETY>(0x3e);
	check<CRC_8_ROHC>(0xd0);
	check<CRC_8_SAE_J1850>(0x4b);
	check<CRC_8_SMBUS>(0xf4);
	check<CRC_8_TECH_3250>(0x97);
	check<CRC_8_WCDMA>(0x25);
	check<CRC_10_ATM>(0x199);
	check<CRC_10_CDMA2000>(0x233);
	check<CRC_10_GSM>(0x12a);
	check<CRC_11_FLEXRAY>(0x5a3);
	check<CRC_11_UMTS>(0x061);
	check<CRC_12_CDMA2000>(0xd4d);
	check<CRC_12_DECT>(0xf5b);
	check<CRC_12_GSM>(0xb34);
	check<CRC_12_UMTS>(0xdaf);
	check<CRC_13_BBC>(0x04fa);
	check<CRC_14_DARC>(0x82d);
	check<CRC_14_GSM>(0x30ae);
	check<CRC_15_CAN>(0x059e);
	check<CRC_15_MPT1327>(0x2566);
	check<CRC_16_ARC>(0xbb3d);
	check<CRC_16_CDMA2000>(0x4c06);
	check<CRC_16_CMS>(0xaee7);
	check<CRC_16_DDS_110>(0x9ecf);
	check<CRC_16_DECT_R>(0x007e);
	check<CRC_16_DECT_X>(0x007f);
	check<CRC_16_DNP>(0xea82);
	check<CRC_16_EN_13757>(0xc2b7);
	check<CRC_16_GENIBUS>(0xd64e);
	check<CRC_16_GSM>(0xce3c);
	check<CRC_16_IBM_3740>(0x29b1);
	check<CRC_16_IBM_SDLC>(0x906e);
	check<CRC_16_ISO_IEC_14443_3_A>(0xbf05);
	check<CRC_16_KERMIT>(0x2189);
	check<CRC_16_LJ1200>(0xbdf4);
	check<CRC_16_M17>(0x772b);
	check<CRC_16_MAXIM_DOW>(0x44c2);
	check<CRC_16_MCRF4XX>(0x6f91);
	check<CRC_16_MODBUS>(0x4b37);
	check<CRC_16_NRSC_5>(0xa066);
	check<CRC_16_OPENSAFETY_A>(0x5d38);
	check<CRC_16_OPENSAFETY_B>(0x20fe);
	check<CRC_16_PROFIBUS>(0xa819);
	check<CRC_16_RIELLO>(0x63d0);
	check<CRC_16_SPI_FUJITSU>(0xe5cc);
	check<CRC_16_T10_DIF>(0xd0db);
	check<CRC_16_TELEDISK>(0x0fb3);
	check<CRC_16_TMS37157>(0x26b1);
	check<CRC_16_UMTS>(0xfee8);
	check<CRC_16_USB>(0xb4c8);
	check<CRC_16_XMODEM>(0x31c3);
	check<CRC_17_CAN_FD>(0x04f03);
	check<CRC_21_CAN_FD>(0xed841);
	check<CRC_24_BLE>(0xc25a56);
	check<CRC_24_FLEXRAY_A>(0x7979bd);
	check<CRC_24_FLEXRAY_B>(0x1f23b8);
	check<CRC_24_INTERLAKEN>(0xb4f3e6);
	check<CRC_24_LTE_A>(0xcde703);
	check<CRC_24_LTE_B>(0x23ef52);
	check<CRC_24_OPENPGP>(0x21cf02);
	check<CRC_24_OS_9>(0x200fa5);
	check<CRC_30_CDMA>(0x04c34abf);
	check<CRC_31_PHILIPS>(0x0ce9e46c);
	check<CRC_32_AIXM>(0x3010bf7f);
	check<CRC_32_AUTOSAR>(0x1697d06a);
	check<CRC_32_BASE91_D>(0x87315576);
	check<CRC_32_BZIP2>(0xfc891918);
	check<CRC_32_CD_ROM_EDC>(0x6ec2edc4);
	check<CRC_32_CKSUM>(0x765e7680);
	check<CRC_32_ISCSI>(0xe3069283);
	check<CRC_32_ISO_HDLC>(0xcbf43926);
	check<CRC_32_JAMCRC>(0x340bc6d9);
	check<CRC_32_MEF>(0xd2c22f51);
	check<CRC_32_MPEG_2>(0x376e6e7);
	check<CRC_32_XFER>(0xbd0be338);
	check<CRC_40_GSM>(0xd4164fc646);
	check<CRC_64_ECMA_182>(0x6c40df5f0b497347);
	check<CRC_64_GO_ISO>(0xb90956c775a41001);
	check<CRC_64_MS>(0x75d4b74f024eceea);
	check<CRC_64_NVME>(0xae8b14860a799888);
	check<CRC_64_REDIS>(0xe9c6d914c4b8d9ca);
	check<CRC_64_WE>(0x62ec59e3f1a4f00a);
	check<CRC_64_XZ>(0x995dc9bbdf1939fa);

	return 0;
}


