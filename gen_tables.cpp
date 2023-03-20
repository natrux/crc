#include <crc/crc.h>
#include <cstdint>
#include <iostream>
#include <fstream>

#include <crc_3_gsm.inl>
#include <crc_3_rohc.inl>
#include <crc_4_g_704.inl>
#include <crc_4_interlaken.inl>
#include <crc_5_epc_c1g2.inl>
#include <crc_5_g_704.inl>
#include <crc_5_usb.inl>
#include <crc_6_cdma2000_a.inl>
#include <crc_6_cdma2000_b.inl>
#include <crc_6_darc.inl>
#include <crc_6_g_704.inl>
#include <crc_6_gsm.inl>
#include <crc_7_mmc.inl>
#include <crc_7_rohc.inl>
#include <crc_7_umts.inl>
#include <crc_8_autosar.inl>
#include <crc_8_bluetooth.inl>
#include <crc_8_cdma2000.inl>
#include <crc_8_darc.inl>
#include <crc_8_dvb_s2.inl>
#include <crc_8_gsm_a.inl>
#include <crc_8_gsm_b.inl>
#include <crc_8_hitag.inl>
#include <crc_8_i_432_1.inl>
#include <crc_8_i_code.inl>
#include <crc_8_lte.inl>
#include <crc_8_maxim_dow.inl>
#include <crc_8_mifare_mad.inl>
#include <crc_8_nrsc_5.inl>
#include <crc_8_opensafety.inl>
#include <crc_8_rohc.inl>
#include <crc_8_sae_j1850.inl>
#include <crc_8_smbus.inl>
#include <crc_8_tech_3250.inl>
#include <crc_8_wcdma.inl>
#include <crc_10_atm.inl>
#include <crc_10_cdma2000.inl>
#include <crc_10_gsm.inl>
#include <crc_11_flexray.inl>
#include <crc_11_umts.inl>
#include <crc_12_cdma2000.inl>
#include <crc_12_dect.inl>
#include <crc_12_gsm.inl>
#include <crc_12_umts.inl>
#include <crc_13_bbc.inl>
#include <crc_14_darc.inl>
#include <crc_14_gsm.inl>
#include <crc_15_can.inl>
#include <crc_15_mpt1327.inl>
#include <crc_16_arc.inl>
#include <crc_16_cdma2000.inl>
#include <crc_16_cms.inl>
#include <crc_16_dds_110.inl>
#include <crc_16_dect_r.inl>
#include <crc_16_dect_x.inl>
#include <crc_16_dnp.inl>
#include <crc_16_en_13757.inl>
#include <crc_16_genibus.inl>
#include <crc_16_gsm.inl>
#include <crc_16_ibm_3740.inl>
#include <crc_16_ibm_sdlc.inl>
#include <crc_16_iso_iec_14443_3_a.inl>
#include <crc_16_kermit.inl>
#include <crc_16_lj1200.inl>
#include <crc_16_m17.inl>
#include <crc_16_maxim_dow.inl>
#include <crc_16_mcrf4xx.inl>
#include <crc_16_modbus.inl>
#include <crc_16_nrsc_5.inl>
#include <crc_16_opensafety_a.inl>
#include <crc_16_opensafety_b.inl>
#include <crc_16_profibus.inl>
#include <crc_16_riello.inl>
#include <crc_16_spi_fujitsu.inl>
#include <crc_16_t10_dif.inl>
#include <crc_16_teledisk.inl>
#include <crc_16_tms37157.inl>
#include <crc_16_umts.inl>
#include <crc_16_usb.inl>
#include <crc_16_xmodem.inl>
#include <crc_17_can_fd.inl>
#include <crc_21_can_fd.inl>
#include <crc_24_ble.inl>
#include <crc_24_flexray_a.inl>
#include <crc_24_flexray_b.inl>
#include <crc_24_interlaken.inl>
#include <crc_24_lte_a.inl>
#include <crc_24_lte_b.inl>
#include <crc_24_openpgp.inl>
#include <crc_24_os_9.inl>
#include <crc_30_cdma.inl>
#include <crc_31_philips.inl>
#include <crc_32_aixm.inl>
#include <crc_32_autosar.inl>
#include <crc_32_base91_d.inl>
#include <crc_32_bzip2.inl>
#include <crc_32_cd_rom_edc.inl>
#include <crc_32_cksum.inl>
#include <crc_32_iso_hdlc.inl>
#include <crc_32_iscsi.inl>
#include <crc_32_jamcrc.inl>
#include <crc_32_mef.inl>
#include <crc_32_mpeg_2.inl>
#include <crc_32_xfer.inl>
#include <crc_40_gsm.inl>
#include <crc_64_ecma_182.inl>
#include <crc_64_go_iso.inl>
#include <crc_64_ms.inl>
#include <crc_64_we.inl>
#include <crc_64_xz.inl>



size_t calc_line_break(size_t bit_size){
	static const size_t divisor_table[257] = {
		1,
		1,
		2, 2,
		4, 4, 4, 4,
		8, 8, 8, 8, 8, 8, 8, 8,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
		256,
	};

	const size_t line_space = 120;
	const size_t tab_space = 8;
	const size_t ideal = (line_space - tab_space + 1) / (4 + bit_size / 4);
	return divisor_table[std::min(ideal, static_cast<size_t>(256))];
}


template<class C>
void print_table(std::ostream &out){
	typename C::R tab[256];
	C::calc_table(tab);

	const size_t line_break = calc_line_break(C::bit_size);

	out << "{" << std::endl;
	for(size_t i=0; i<256; i++){
		if(i % line_break == 0){
			out << "\t";
		}
		out << "0x" << std::hex << static_cast<uint64_t>(tab[i]) << std::dec << ",";
		if(i % line_break == line_break-1){
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
	out << "#include <crc/crc.h>" << std::endl;
	out << "#include <cstdint>" << std::endl << std::endl << std::endl << std::endl;
	out << "using " << class_name << " = " << full_type << ";" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "const uint_w<" << width << "> " << class_name << "::table[256];";
	out << std::endl << std::endl;
}


template<class C>
void print_src(std::ostream &out, const std::string &class_name, const std::string &lower_class_name, const std::string &width){
	out << "#include <crc/" << lower_class_name << ".h>" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "const uint_w<" << width << "> " << class_name << "::table[256] = ";
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
		std::ifstream stream("declarations/"+lower_class_name+".inl");
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
		std::ofstream stream("tables/include/crc/"+lower_class_name+".h");
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

