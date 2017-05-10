# $NetBSD$

DISTNAME=	libretro-core-info-20170410
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core information

GITHUB_PROJECT=	libretro-super
GITHUB_TAG=	36784a1b876a14005e94daf4e5b08873e8ff9615

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/dist/info

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

INSTALL_FILES=	00_example_libretro.info \
		2048_libretro.info \
		3dengine_libretro.info \
		4do_libretro.info \
		81_libretro.info \
		advanced_tests_libretro.info \
		atari800_libretro.info \
		beetle_psx_libretro.info \
		blastem_libretro.info \
		bluemsx_libretro.info \
		bnes_libretro.info \
		bsnes_accuracy_libretro.info \
		bsnes_balanced_libretro.info \
		bsnes_cplusplus98_libretro.info \
		bsnes_mercury_accuracy_libretro.info \
		bsnes_mercury_balanced_libretro.info \
		bsnes_mercury_performance_libretro.info \
		bsnes_performance_libretro.info \
		cap32_libretro.info \
		craft_libretro.info \
		crocods_libretro.info \
		cruzes_libretro.info \
		desmume_libretro.info \
		dinothawr_libretro.info \
		dolphin_launcher_libretro.info \
		dolphin_libretro.info \
		dosbox_libretro.info \
		easyrpg_libretro.info \
		emux_chip8_libretro.info \
		emux_gb_libretro.info \
		emux_nes_libretro.info \
		emux_sms_libretro.info \
		fbalpha2012_cps1_libretro.info \
		fbalpha2012_cps2_libretro.info \
		fbalpha2012_cps3_libretro.info \
		fbalpha2012_libretro.info \
		fbalpha2012_neogeo_libretro.info \
		fbalpha_libretro.info \
		fceumm_libretro.info \
		ffmpeg_libretro.info \
		fmsx_libretro.info \
		fsuae_libretro.info \
		fuse_libretro.info \
		gambatte_libretro.info \
		genesis_plus_gx_libretro.info \
		gme_libretro.info \
		gpsp_libretro.info \
		gw_libretro.info \
		handy_libretro.info \
		hatari_libretro.info \
		imageviewer_libretro.info \
		lutro_libretro.info \
		mame2000_libretro.info \
		mame2003_libretro.info \
		mame2003_midway_libretro.info \
		mame2010_libretro.info \
		mame2014_libretro.info \
		mame2016_libretro.info \
		mame_libretro.info \
		mednafen_gba_libretro.info \
		mednafen_lynx_libretro.info \
		mednafen_ngp_libretro.info \
		mednafen_pce_fast_libretro.info \
		mednafen_pcfx_libretro.info \
		mednafen_psx_hw_libretro.info \
		mednafen_psx_libretro.info \
		mednafen_saturn_libretro.info \
		mednafen_snes_libretro.info \
		mednafen_supergrafx_libretro.info \
		mednafen_vb_libretro.info \
		mednafen_wswan_libretro.info \
		melonds_libretro.info \
		mess2014_libretro.info \
		meteor_libretro.info \
		mgba_libretro.info \
		mrboom_libretro.info \
		mupen64plus_gles3_libretro.info \
		mupen64plus_libretro.info \
		nestopia_libretro.info \
		nxengine_libretro.info \
		o2em_libretro.info \
		parallel_n64_debug_libretro.info \
		parallel_n64_libretro.info \
		pascal_pong_libretro.info \
		pcem_libretro.info \
		pcsx1_libretro.info \
		pcsx_rearmed_interpreter_libretro.info \
		pcsx_rearmed_libretro.info \
		pcsx_rearmed_libretro_neon.info \
		picodrive_libretro.info \
		pocketcdg_libretro.info \
		pokemini_libretro.info \
		ppsspp_libretro.info \
		prboom_libretro.info \
		prosystem_libretro.info \
		psp1_libretro.info \
		puae_libretro.info \
		quicknes_libretro.info \
		reicast_libretro.info \
		reicast_naomi_libretro.info \
		remotejoy_libretro.info \
		rustation_libretro.info \
		scummvm_libretro.info \
		snes9x2002_libretro.info \
		snes9x2005_libretro.info \
		snes9x2005_plus_libretro.info \
		snes9x2010_libretro.info \
		snes9x_libretro.info \
		stella_libretro.info \
		stonesoup_libretro.info \
		tempgba_libretro.info \
		test_libretro.info \
		test_netplay_libretro.info \
		testaudio_callback_libretro.info \
		testaudio_no_callback_libretro.info \
		testaudio_playback_wav_libretro.info \
		testgl_compute_shaders_libretro.info \
		testgl_ff_libretro.info \
		testgl_libretro.info \
		testinput_buttontest_libretro.info \
		testretroluxury_libretro.info \
		testsw_libretro.info \
		testsw_vram_libretro.info \
		testvulkan_async_compute_libretro.info \
		testvulkan_libretro.info \
		tgbdual_libretro.info \
		tyrquake_libretro.info \
		uae4arm_libretro.info \
		ume2014_libretro.info \
		uzem_libretro.info \
		vba_next_libretro.info \
		vbam_libretro.info \
		vecx_libretro.info \
		vice_x128_libretro.info \
		vice_x64_libretro.info \
		virtualjaguar_libretro.info \
		xrick_libretro.info \
		yabause_libretro.info

do-install:
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} \
	    ${DESTDIR}${PREFIX}/share/libretro/info/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
