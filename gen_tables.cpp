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
#include <crc_64_nvme.inl>
#include <crc_64_redis.inl>
#include <crc_64_we.inl>
#include <crc_64_xz.inl>



std::string declarations_dir;
std::string tables_dir;


static size_t calc_line_break(size_t bit_size){
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
	out << "const uint_w<" << width << "> " << class_name << "::table[256];" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "const char *" << class_name << "::name;" << std::endl << std::endl;
}


template<class C>
void print_src(std::ostream &out, const std::string &algorithm_name, const std::string &class_name, const std::string &lower_class_name, const std::string &width){
	out << "#include <crc/" << lower_class_name << ".h>" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "const uint_w<" << width << "> " << class_name << "::table[256] = ";
	print_table<C>(out);
	out << ";" << std::endl << std::endl;
	out << "template<>" << std::endl;
	out << "const char *" << class_name << "::name = \"" << algorithm_name << "\";" << std::endl << std::endl;
}


template<class C>
void generate_table(const std::string &algorithm_name){
	std::string class_name = algorithm_name;
	{
		size_t pos = 0;
		while(pos != std::string::npos){
			pos = class_name.find_first_of("-/", pos);
			if(pos != std::string::npos){
				auto &chr = class_name.at(pos);
				if(chr == '-'){
					chr = '_';
				}else if(chr == '/'){
					chr = '_';
				}
			}
		}
	}

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
		std::ifstream stream(declarations_dir+"/"+lower_class_name+".inl");
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
		std::ofstream stream(tables_dir+"/include/crc/"+lower_class_name+".h");
		print_header<C>(stream, class_name, full_type, int_width);
	}
	{
		std::ofstream stream(tables_dir+"/src/"+lower_class_name+".cpp");
		print_src<C>(stream, algorithm_name, class_name, lower_class_name, int_width);
	}
}


static void generate_all_tables(){
	generate_table<CRC_3_GSM>("CRC-3/GSM");
	generate_table<CRC_3_ROHC>("CRC-3/ROHC");
	generate_table<CRC_4_G_704>("CRC-4/G-704");
	generate_table<CRC_4_INTERLAKEN>("CRC-4/INTERLAKEN");
	generate_table<CRC_5_EPC_C1G2>("CRC-5/EPC-C1G2");
	generate_table<CRC_5_G_704>("CRC-5/G-704");
	generate_table<CRC_5_USB>("CRC-5/USB");
	generate_table<CRC_6_CDMA2000_A>("CRC-6/CDMA2000-A");
	generate_table<CRC_6_CDMA2000_B>("CRC-6/CDMA2000-B");
	generate_table<CRC_6_DARC>("CRC-6/DARC");
	generate_table<CRC_6_G_704>("CRC-6/G-704");
	generate_table<CRC_6_GSM>("CRC-6/GSM");
	generate_table<CRC_7_MMC>("CRC-7/MMC");
	generate_table<CRC_7_ROHC>("CRC-7/ROHC");
	generate_table<CRC_7_UMTS>("CRC-7/UMTS");
	generate_table<CRC_8_AUTOSAR>("CRC-8/AUTOSAR");
	generate_table<CRC_8_BLUETOOTH>("CRC-8/BLUETOOTH");
	generate_table<CRC_8_CDMA2000>("CRC-8/CDMA2000");
	generate_table<CRC_8_DARC>("CRC-8/DARC");
	generate_table<CRC_8_DVB_S2>("CRC-8/DVB-S2");
	generate_table<CRC_8_GSM_A>("CRC-8/GSM-A");
	generate_table<CRC_8_GSM_B>("CRC-8/GSM-B");
	generate_table<CRC_8_HITAG>("CRC-8/HITAG");
	generate_table<CRC_8_I_432_1>("CRC-8/I-432-1");
	generate_table<CRC_8_I_CODE>("CRC-8/I-CODE");
	generate_table<CRC_8_LTE>("CRC-8/LTE");
	generate_table<CRC_8_MAXIM_DOW>("CRC-8/MAXIM-DOW");
	generate_table<CRC_8_MIFARE_MAD>("CRC-8/MIFARE-MAD");
	generate_table<CRC_8_NRSC_5>("CRC-8/NRSC-5");
	generate_table<CRC_8_OPENSAFETY>("CRC-8/OPENSAFETY");
	generate_table<CRC_8_ROHC>("CRC-8/ROHC");
	generate_table<CRC_8_SAE_J1850>("CRC-8/SAE-J1850");
	generate_table<CRC_8_SMBUS>("CRC-8/SMBUS");
	generate_table<CRC_8_TECH_3250>("CRC-8/TECH-3250");
	generate_table<CRC_8_WCDMA>("CRC-8/WCDMA");
	generate_table<CRC_10_ATM>("CRC-10/ATM");
	generate_table<CRC_10_CDMA2000>("CRC-10/CDMA2000");
	generate_table<CRC_10_GSM>("CRC-10/GSM");
	generate_table<CRC_11_FLEXRAY>("CRC-11/FLEXRAY");
	generate_table<CRC_11_UMTS>("CRC-11/UMTS");
	generate_table<CRC_12_CDMA2000>("CRC-12/CDMA2000");
	generate_table<CRC_12_DECT>("CRC-12/DECT");
	generate_table<CRC_12_GSM>("CRC-12/GSM");
	generate_table<CRC_12_UMTS>("CRC-12/UMTS");
	generate_table<CRC_13_BBC>("CRC-13/BBC");
	generate_table<CRC_14_DARC>("CRC-14/DARC");
	generate_table<CRC_14_GSM>("CRC-14/GSM");
	generate_table<CRC_15_CAN>("CRC-15/CAN");
	generate_table<CRC_15_MPT1327>("CRC-15/MPT1327");
	generate_table<CRC_16_ARC>("CRC-16/ARC");
	generate_table<CRC_16_CDMA2000>("CRC-16/CDMA2000");
	generate_table<CRC_16_CMS>("CRC-16/CMS");
	generate_table<CRC_16_DDS_110>("CRC-16/DDS-110");
	generate_table<CRC_16_DECT_R>("CRC-16/DECT-R");
	generate_table<CRC_16_DECT_X>("CRC-16/DECT-X");
	generate_table<CRC_16_DNP>("CRC-16/DNP");
	generate_table<CRC_16_EN_13757>("CRC-16/EN-13757");
	generate_table<CRC_16_GENIBUS>("CRC-16/GENIBUS");
	generate_table<CRC_16_GSM>("CRC-16/GSM");
	generate_table<CRC_16_IBM_3740>("CRC-16/IBM-3740");
	generate_table<CRC_16_IBM_SDLC>("CRC-16/IBM-SDLC");
	generate_table<CRC_16_ISO_IEC_14443_3_A>("CRC-16/ISO-IEC-14443-3-A");
	generate_table<CRC_16_KERMIT>("CRC-16/KERMIT");
	generate_table<CRC_16_LJ1200>("CRC-16/LJ1200");
	generate_table<CRC_16_M17>("CRC-16/M17");
	generate_table<CRC_16_MAXIM_DOW>("CRC-16/MAXIM-DOW");
	generate_table<CRC_16_MCRF4XX>("CRC-16/MCRF4XX");
	generate_table<CRC_16_MODBUS>("CRC-16/MODBUS");
	generate_table<CRC_16_NRSC_5>("CRC-16/NRSC-5");
	generate_table<CRC_16_OPENSAFETY_A>("CRC-16/OPENSAFETY-A");
	generate_table<CRC_16_OPENSAFETY_B>("CRC-16/OPENSAFETY-B");
	generate_table<CRC_16_PROFIBUS>("CRC-16/PROFIBUS");
	generate_table<CRC_16_RIELLO>("CRC-16/RIELLO");
	generate_table<CRC_16_SPI_FUJITSU>("CRC-16/SPI-FUJITSU");
	generate_table<CRC_16_T10_DIF>("CRC-16/T10-DIF");
	generate_table<CRC_16_TELEDISK>("CRC-16/TELEDISK");
	generate_table<CRC_16_TMS37157>("CRC-16/TMS37157");
	generate_table<CRC_16_UMTS>("CRC-16/UMTS");
	generate_table<CRC_16_USB>("CRC-16/USB");
	generate_table<CRC_16_XMODEM>("CRC-16/XMODEM");
	generate_table<CRC_17_CAN_FD>("CRC-17/CAN-FD");
	generate_table<CRC_21_CAN_FD>("CRC-21/CAN-FD");
	generate_table<CRC_24_BLE>("CRC-24/BLE");
	generate_table<CRC_24_FLEXRAY_A>("CRC-24/FLEXRAY-A");
	generate_table<CRC_24_FLEXRAY_B>("CRC-24/FLEXRAY-B");
	generate_table<CRC_24_INTERLAKEN>("CRC-24/INTERLAKEN");
	generate_table<CRC_24_LTE_A>("CRC-24/LTE-A");
	generate_table<CRC_24_LTE_B>("CRC-24/LTE-B");
	generate_table<CRC_24_OPENPGP>("CRC-24/OPENPGP");
	generate_table<CRC_24_OS_9>("CRC-24/OS-9");
	generate_table<CRC_30_CDMA>("CRC-30/CDMA");
	generate_table<CRC_31_PHILIPS>("CRC-31/PHILIPS");
	generate_table<CRC_32_AIXM>("CRC-32/AIXM");
	generate_table<CRC_32_AUTOSAR>("CRC-32/AUTOSAR");
	generate_table<CRC_32_BASE91_D>("CRC-32/BASE91-D");
	generate_table<CRC_32_BZIP2>("CRC-32/BZIP2");
	generate_table<CRC_32_CD_ROM_EDC>("CRC-32/CD-ROM-EDC");
	generate_table<CRC_32_CKSUM>("CRC-32/CKSUM");
	generate_table<CRC_32_ISCSI>("CRC-32/ISCSI");
	generate_table<CRC_32_ISO_HDLC>("CRC-32/ISO-HDLC");
	generate_table<CRC_32_JAMCRC>("CRC-32/JAMCRC");
	generate_table<CRC_32_MEF>("CRC-32/MEF");
	generate_table<CRC_32_MPEG_2>("CRC-32/MPEG-2");
	generate_table<CRC_32_XFER>("CRC-32/XFER");
	generate_table<CRC_40_GSM>("CRC-40/GSM");
	generate_table<CRC_64_ECMA_182>("CRC-64/ECMA-182");
	generate_table<CRC_64_GO_ISO>("CRC-64/GO-ISO");
	generate_table<CRC_64_MS>("CRC-64/MS");
	generate_table<CRC_64_NVME>("CRC-64/NVME");
	generate_table<CRC_64_REDIS>("CRC-64/REDIS");
	generate_table<CRC_64_WE>("CRC-64/WE");
	generate_table<CRC_64_XZ>("CRC-64/XZ");
}


static void usage(const std::string &arg0){
	std::cout << "Usage: " << arg0 << " declarations_dir tables_dir" << std::endl;
	std::cout << "Where" << std::endl;
	std::cout << "    declarations_dir is the input folder with the inline declarations" << std::endl;
	std::cout << "    tables_dir is the output folder" << std::endl;
}


int main(int argc, char **argv){
	if(argc != 3){
		usage(argv[0]);
		return 1;
	}
	declarations_dir = argv[1];
	tables_dir = argv[2];

	generate_all_tables();

	return 0;
}

