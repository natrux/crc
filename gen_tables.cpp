#include "crc.h"
#include <cstdint>
#include <iostream>
#include <fstream>

#include "crc_3_gsm.h"
#include "crc_3_rohc.h"
#include "crc_4_g_704.h"
#include "crc_4_interlaken.h"
#include "crc_5_epc_c1g2.h"
#include "crc_5_g_704.h"
#include "crc_5_usb.h"
#include "crc_6_cdma2000_a.h"
#include "crc_6_cdma2000_b.h"
#include "crc_6_darc.h"
#include "crc_6_g_704.h"
#include "crc_6_gsm.h"
#include "crc_7_mmc.h"
#include "crc_7_rohc.h"
#include "crc_7_umts.h"
#include "crc_8_autosar.h"
#include "crc_8_bluetooth.h"
#include "crc_8_cdma2000.h"
#include "crc_8_darc.h"
#include "crc_8_dvb_s2.h"
#include "crc_8_gsm_a.h"
#include "crc_8_gsm_b.h"
#include "crc_8_hitag.h"
#include "crc_8_i_432_1.h"
#include "crc_8_i_code.h"
#include "crc_8_lte.h"
#include "crc_8_maxim_dow.h"
#include "crc_8_mifare_mad.h"
#include "crc_8_nrsc_5.h"
#include "crc_8_opensafety.h"
#include "crc_8_rohc.h"
#include "crc_8_sae_j1850.h"
#include "crc_8_smbus.h"
#include "crc_8_tech_3250.h"
#include "crc_8_wcdma.h"
#include "crc_10_atm.h"
#include "crc_10_cdma2000.h"
#include "crc_10_gsm.h"
#include "crc_11_flexray.h"
#include "crc_11_umts.h"
#include "crc_12_cdma2000.h"
#include "crc_12_dect.h"
#include "crc_12_gsm.h"
#include "crc_12_umts.h"
#include "crc_13_bbc.h"
#include "crc_14_darc.h"
#include "crc_14_gsm.h"
#include "crc_15_can.h"
#include "crc_15_mpt1327.h"
#include "crc_16_arc.h"
#include "crc_16_cdma2000.h"
#include "crc_16_cms.h"
#include "crc_16_dds_110.h"
#include "crc_16_dect_r.h"
#include "crc_16_dect_x.h"
#include "crc_16_dnp.h"
#include "crc_16_en_13757.h"
#include "crc_16_genibus.h"
#include "crc_16_gsm.h"
#include "crc_16_ibm_3740.h"
#include "crc_16_ibm_sdlc.h"
#include "crc_16_iso_iec_14443_3_a.h"
#include "crc_16_kermit.h"
#include "crc_16_lj1200.h"
#include "crc_16_m17.h"
#include "crc_16_maxim_dow.h"
#include "crc_16_mcrf4xx.h"
#include "crc_16_modbus.h"
#include "crc_16_nrsc_5.h"
#include "crc_16_opensafety_a.h"
#include "crc_16_opensafety_b.h"
#include "crc_16_profibus.h"
#include "crc_16_riello.h"
#include "crc_16_spi_fujitsu.h"
#include "crc_16_t10_dif.h"
#include "crc_16_teledisk.h"
#include "crc_16_tms37157.h"
#include "crc_16_umts.h"
#include "crc_16_usb.h"
#include "crc_16_xmodem.h"
#include "crc_17_can_fd.h"
#include "crc_21_can_fd.h"
#include "crc_24_ble.h"
#include "crc_24_flexray_a.h"
#include "crc_24_flexray_b.h"
#include "crc_24_interlaken.h"
#include "crc_24_lte_a.h"
#include "crc_24_lte_b.h"
#include "crc_24_openpgp.h"
#include "crc_24_os_9.h"
#include "crc_30_cdma.h"
#include "crc_31_philips.h"
#include "crc_32_aixm.h"
#include "crc_32_autosar.h"
#include "crc_32_base91_d.h"
#include "crc_32_bzip2.h"
#include "crc_32_cd_rom_edc.h"
#include "crc_32_cksum.h"
#include "crc_32_iso_hdlc.h"
#include "crc_32_iscsi.h"
#include "crc_32_jamcrc.h"
#include "crc_32_mef.h"
#include "crc_32_mpeg_2.h"
#include "crc_32_xfer.h"
#include "crc_40_gsm.h"
#include "crc_64_ecma_182.h"
#include "crc_64_go_iso.h"
#include "crc_64_ms.h"
#include "crc_64_we.h"
#include "crc_64_xz.h"



template<class C>
void print_table(std::ostream &out){
	typename C::R tab[256];
	C::calc_table(tab);
	out << "{" << std::endl;
	for(size_t i=0; i<256; i++){
		if(i % 4 == 0){
			out << "\t";
		}
		out << "0x" << std::hex << static_cast<uint64_t>(tab[i]) << std::dec << ",";
		if(i % 4 == 3){
			out << std::endl;
		}else{
			out << " ";
		}
	}
	out << "}";
}


template<class C>
void print_header(std::ostream &out, const std::string &class_name, const std::string &full_type, const std::string &width){
	out << "#pragma once" << std::endl << std::endl;
	out << "#include \"crc.h\"" << std::endl;
	out << "#include <cstdint>" << std::endl << std::endl << std::endl << std::endl;
	out << "using " << class_name << " = " << full_type << ";" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "uint_w<" << width << "> " << class_name << "::table[256];";
	out << std::endl << std::endl;
}


template<class C>
void print_src(std::ostream &out, const std::string &class_name, const std::string &lower_class_name, const std::string &width){
	out << "#include \"" << lower_class_name << ".h\"" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "uint_w<" << width << "> " << class_name << "::table[256] = ";
	print_table<C>(out);
	out << ";" << std::endl << std::endl;
}


template<class C>
void generate_table(const std::string &class_name){
	std::string lower_class_name;
	{
		lower_class_name.resize(class_name.length());
		for(size_t i=0; i<class_name.length(); i++){
			char c = class_name[i];
			if(c >= 'A' && c <= 'Z'){
				c += 32;
			}
			lower_class_name[i] = c;
		}
	}
	std::string full_type;
	{
		std::ifstream stream("declarations/"+lower_class_name+".h");
		std::string line;
		std::getline(stream, line);
		size_t pos1 = line.find(" = ") + 3;
		size_t pos2 = line.rfind(";");
		full_type = line.substr(pos1, pos2-pos1);
	}
	std::string int_width;
	{
		size_t pos1 = full_type.find("<") + 1;
		size_t pos2 = full_type.find(",", pos1);
		int_width = full_type.substr(pos1, pos2-pos1);
	}

	{
		std::ofstream stream("tables/include/"+lower_class_name+".h");
		print_header<C>(stream, class_name, full_type, int_width);
	}
	{
		std::ofstream stream("tables/src/"+lower_class_name+".cpp");
		print_src<C>(stream, class_name, lower_class_name, int_width);
	}
}


void generate_all_tables(){
	generate_table<CRC_3_GSM>("CRC_3_GSM");
	generate_table<CRC_3_ROHC>("CRC_3_ROHC");
	generate_table<CRC_4_G_704>("CRC_4_G_704");
	generate_table<CRC_4_INTERLAKEN>("CRC_4_INTERLAKEN");
	generate_table<CRC_5_EPC_C1G2>("CRC_5_EPC_C1G2");
	generate_table<CRC_5_G_704>("CRC_5_G_704");
	generate_table<CRC_5_USB>("CRC_5_USB");
	generate_table<CRC_6_CDMA2000_A>("CRC_6_CDMA2000_A");
	generate_table<CRC_6_CDMA2000_B>("CRC_6_CDMA2000_B");
	generate_table<CRC_6_DARC>("CRC_6_DARC");
	generate_table<CRC_6_G_704>("CRC_6_G_704");
	generate_table<CRC_6_GSM>("CRC_6_GSM");
	generate_table<CRC_7_MMC>("CRC_7_MMC");
	generate_table<CRC_7_ROHC>("CRC_7_ROHC");
	generate_table<CRC_7_UMTS>("CRC_7_UMTS");
	generate_table<CRC_8_AUTOSAR>("CRC_8_AUTOSAR");
	generate_table<CRC_8_BLUETOOTH>("CRC_8_BLUETOOTH");
	generate_table<CRC_8_CDMA2000>("CRC_8_CDMA2000");
	generate_table<CRC_8_DARC>("CRC_8_DARC");
	generate_table<CRC_8_DVB_S2>("CRC_8_DVB_S2");
	generate_table<CRC_8_GSM_A>("CRC_8_GSM_A");
	generate_table<CRC_8_GSM_B>("CRC_8_GSM_B");
	generate_table<CRC_8_HITAG>("CRC_8_HITAG");
	generate_table<CRC_8_I_432_1>("CRC_8_I_432_1");
	generate_table<CRC_8_I_CODE>("CRC_8_I_CODE");
	generate_table<CRC_8_LTE>("CRC_8_LTE");
	generate_table<CRC_8_MAXIM_DOW>("CRC_8_MAXIM_DOW");
	generate_table<CRC_8_MIFARE_MAD>("CRC_8_MIFARE_MAD");
	generate_table<CRC_8_NRSC_5>("CRC_8_NRSC_5");
	generate_table<CRC_8_OPENSAFETY>("CRC_8_OPENSAFETY");
	generate_table<CRC_8_ROHC>("CRC_8_ROHC");
	generate_table<CRC_8_SAE_J1850>("CRC_8_SAE_J1850");
	generate_table<CRC_8_SMBUS>("CRC_8_SMBUS");
	generate_table<CRC_8_TECH_3250>("CRC_8_TECH_3250");
	generate_table<CRC_8_WCDMA>("CRC_8_WCDMA");
	generate_table<CRC_10_ATM>("CRC_10_ATM");
	generate_table<CRC_10_CDMA2000>("CRC_10_CDMA2000");
	generate_table<CRC_10_GSM>("CRC_10_GSM");
	generate_table<CRC_11_FLEXRAY>("CRC_11_FLEXRAY");
	generate_table<CRC_11_UMTS>("CRC_11_UMTS");
	generate_table<CRC_12_CDMA2000>("CRC_12_CDMA2000");
	generate_table<CRC_12_DECT>("CRC_12_DECT");
	generate_table<CRC_12_GSM>("CRC_12_GSM");
	generate_table<CRC_12_UMTS>("CRC_12_UMTS");
	generate_table<CRC_13_BBC>("CRC_13_BBC");
	generate_table<CRC_14_DARC>("CRC_14_DARC");
	generate_table<CRC_14_GSM>("CRC_14_GSM");
	generate_table<CRC_15_CAN>("CRC_15_CAN");
	generate_table<CRC_15_MPT1327>("CRC_15_MPT1327");
	generate_table<CRC_16_ARC>("CRC_16_ARC");
	generate_table<CRC_16_CDMA2000>("CRC_16_CDMA2000");
	generate_table<CRC_16_CMS>("CRC_16_CMS");
	generate_table<CRC_16_DDS_110>("CRC_16_DDS_110");
	generate_table<CRC_16_DECT_R>("CRC_16_DECT_R");
	generate_table<CRC_16_DECT_X>("CRC_16_DECT_X");
	generate_table<CRC_16_DNP>("CRC_16_DNP");
	generate_table<CRC_16_EN_13757>("CRC_16_EN_13757");
	generate_table<CRC_16_GENIBUS>("CRC_16_GENIBUS");
	generate_table<CRC_16_GSM>("CRC_16_GSM");
	generate_table<CRC_16_IBM_3740>("CRC_16_IBM_3740");
	generate_table<CRC_16_IBM_SDLC>("CRC_16_IBM_SDLC");
	generate_table<CRC_16_ISO_IEC_14443_3_A>("CRC_16_ISO_IEC_14443_3_A");
	generate_table<CRC_16_KERMIT>("CRC_16_KERMIT");
	generate_table<CRC_16_LJ1200>("CRC_16_LJ1200");
	generate_table<CRC_16_M17>("CRC_16_M17");
	generate_table<CRC_16_MAXIM_DOW>("CRC_16_MAXIM_DOW");
	generate_table<CRC_16_MCRF4XX>("CRC_16_MCRF4XX");
	generate_table<CRC_16_MODBUS>("CRC_16_MODBUS");
	generate_table<CRC_16_NRSC_5>("CRC_16_NRSC_5");
	generate_table<CRC_16_OPENSAFETY_A>("CRC_16_OPENSAFETY_A");
	generate_table<CRC_16_OPENSAFETY_B>("CRC_16_OPENSAFETY_B");
	generate_table<CRC_16_PROFIBUS>("CRC_16_PROFIBUS");
	generate_table<CRC_16_RIELLO>("CRC_16_RIELLO");
	generate_table<CRC_16_SPI_FUJITSU>("CRC_16_SPI_FUJITSU");
	generate_table<CRC_16_T10_DIF>("CRC_16_T10_DIF");
	generate_table<CRC_16_TELEDISK>("CRC_16_TELEDISK");
	generate_table<CRC_16_TMS37157>("CRC_16_TMS37157");
	generate_table<CRC_16_UMTS>("CRC_16_UMTS");
	generate_table<CRC_16_USB>("CRC_16_USB");
	generate_table<CRC_16_XMODEM>("CRC_16_XMODEM");
	generate_table<CRC_17_CAN_FD>("CRC_17_CAN_FD");
	generate_table<CRC_21_CAN_FD>("CRC_21_CAN_FD");
	generate_table<CRC_24_BLE>("CRC_24_BLE");
	generate_table<CRC_24_FLEXRAY_A>("CRC_24_FLEXRAY_A");
	generate_table<CRC_24_FLEXRAY_B>("CRC_24_FLEXRAY_B");
	generate_table<CRC_24_INTERLAKEN>("CRC_24_INTERLAKEN");
	generate_table<CRC_24_LTE_A>("CRC_24_LTE_A");
	generate_table<CRC_24_LTE_B>("CRC_24_LTE_B");
	generate_table<CRC_24_OPENPGP>("CRC_24_OPENPGP");
	generate_table<CRC_24_OS_9>("CRC_24_OS_9");
	generate_table<CRC_30_CDMA>("CRC_30_CDMA");
	generate_table<CRC_31_PHILIPS>("CRC_31_PHILIPS");
	generate_table<CRC_32_AIXM>("CRC_32_AIXM");
	generate_table<CRC_32_AUTOSAR>("CRC_32_AUTOSAR");
	generate_table<CRC_32_BASE91_D>("CRC_32_BASE91_D");
	generate_table<CRC_32_BZIP2>("CRC_32_BZIP2");
	generate_table<CRC_32_CD_ROM_EDC>("CRC_32_CD_ROM_EDC");
	generate_table<CRC_32_CKSUM>("CRC_32_CKSUM");
	generate_table<CRC_32_ISCSI>("CRC_32_ISCSI");
	generate_table<CRC_32_ISO_HDLC>("CRC_32_ISO_HDLC");
	generate_table<CRC_32_JAMCRC>("CRC_32_JAMCRC");
	generate_table<CRC_32_MEF>("CRC_32_MEF");
	generate_table<CRC_32_MPEG_2>("CRC_32_MPEG_2");
	generate_table<CRC_32_XFER>("CRC_32_XFER");
	generate_table<CRC_40_GSM>("CRC_40_GSM");
	generate_table<CRC_64_ECMA_182>("CRC_64_ECMA_182");
	generate_table<CRC_64_GO_ISO>("CRC_64_GO_ISO");
	generate_table<CRC_64_MS>("CRC_64_MS");
	generate_table<CRC_64_WE>("CRC_64_WE");
	generate_table<CRC_64_XZ>("CRC_64_XZ");
}


int main(int /*argc*/, char **/*argv*/){
	generate_all_tables();

	return 0;
}

