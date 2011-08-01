GME_MAJOR=	0
GME_MINOR=	5
GME_MICRO=	3

SRCS=	Ay_Apu.cpp Ay_Cpu.cpp Ay_Emu.cpp Blip_Buffer.cpp Classic_Emu.cpp \
	Data_Reader.cpp Dual_Resampler.cpp Effects_Buffer.cpp \
	Fir_Resampler.cpp Gb_Apu.cpp Gb_Cpu.cpp Gb_Oscs.cpp Gbs_Emu.cpp \
	Gme_File.cpp Gym_Emu.cpp Hes_Apu.cpp Hes_Cpu.cpp Hes_Emu.cpp \
	Kss_Cpu.cpp Kss_Emu.cpp Kss_Scc_Apu.cpp M3u_Playlist.cpp \
	Multi_Buffer.cpp Music_Emu.cpp Nes_Apu.cpp Nes_Cpu.cpp \
	Nes_Fme7_Apu.cpp Nes_Namco_Apu.cpp Nes_Oscs.cpp Nes_Vrc6_Apu.cpp \
	Nsf_Emu.cpp Nsfe_Emu.cpp Sap_Apu.cpp Sap_Cpu.cpp Sap_Emu.cpp \
	Sms_Apu.cpp Snes_Spc.cpp Spc_Cpu.cpp Spc_Dsp.cpp Spc_Emu.cpp \
	Vgm_Emu.cpp Vgm_Emu_Impl.cpp Ym2413_Emu.cpp Ym2612_Emu.cpp gme.cpp

HDRS=	gme.h gme_types.h blargg_config.h blargg_common.h blargg_source.h \
	Music_Emu.h Blip_Buffer.h Classic_Emu.h Gme_File.h Data_Reader.h \
	Dual_Resampler.h Effects_Buffer.h Fir_Resampler.h M3u_Playlist.h \
	Multi_Buffer.h

.cpp.o:
	$(LIBTOOL) --mode=compile --tag=CXX $(CXX) -c -I. \
		-DNDEBUG $(CFLAGS) $< -o $(@:.o=.lo)

libgme.la:	$(SRCS:.cpp=.o)
	$(LIBTOOL) --tag=CXX --mode=link $(CXX) -o $@ $(LDFLAGS) \
		$(SRCS:.cpp=.lo) -version-info $(GME_MAJOR):$(GME_MINOR) \
		-rpath $(PREFIX)/lib

all: libgme.la

install:	libgme.la
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(MKDIR) $(DESTDIR)$(PREFIX)/include/gme
	$(INSTALL) -m644 $(HDRS) $(DESTDIR)$(PREFIX)/include/gme/
	$(LIBTOOL) --mode=install $(INSTALL) libgme.la $(DESTDIR)$(PREFIX)/lib/
