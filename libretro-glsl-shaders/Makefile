# $NetBSD$

DISTNAME=	libretro-glsl-shaders-20171011
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
COMMENT=	Libretro GLSL shaders

GITHUB_PROJECT=	glsl-shaders
GITHUB_TAG=	6565f3d5e9a34103a7dce34eec8a7f5332d6f9d1

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes

SHADER_DIRS+=	3dfx
SHADER_DIRS+=	3dfx/shaders
SHADER_DIRS+=	anti-aliasing
SHADER_DIRS+=	anti-aliasing/shaders
SHADER_DIRS+=	anti-aliasing/shaders/aa-shader-4.0-level2
SHADER_DIRS+=	blurs
SHADER_DIRS+=	borders
SHADER_DIRS+=	borders/gameboy-player
SHADER_DIRS+=	borders/gameboy-player/sample-borders
SHADER_DIRS+=	borders/imgborder
SHADER_DIRS+=	borders/resources
SHADER_DIRS+=	borders/sgb
SHADER_DIRS+=	borders/sgb/sample-borders
SHADER_DIRS+=	crt
SHADER_DIRS+=	crt/shaders
SHADER_DIRS+=	crt/shaders/crt-easymode-halation
SHADER_DIRS+=	crt/shaders/crt-hyllian-multipass
SHADER_DIRS+=	crt/shaders/crt-interlaced-halation
SHADER_DIRS+=	crt/shaders/crt-lottes-multipass
SHADER_DIRS+=	crt/shaders/crt-royale
SHADER_DIRS+=	crt/shaders/crt-royale/src
SHADER_DIRS+=	crt/shaders/crtsim
SHADER_DIRS+=	crt/shaders/glow
SHADER_DIRS+=	crt/shaders/gtu-famicom
SHADER_DIRS+=	crt/shaders/gtu-v050
SHADER_DIRS+=	crt/shaders/metacrt
SHADER_DIRS+=	crt/shaders/phosphorlut
SHADER_DIRS+=	crt/shaders/phosphorlut/luts
SHADER_DIRS+=	cubic
SHADER_DIRS+=	cubic/shaders
SHADER_DIRS+=	ddt
SHADER_DIRS+=	ddt/shaders
SHADER_DIRS+=	deblur
SHADER_DIRS+=	deblur/shaders
SHADER_DIRS+=	denoisers
SHADER_DIRS+=	denoisers/shaders
SHADER_DIRS+=	dithering
SHADER_DIRS+=	dithering/shaders
SHADER_DIRS+=	dithering/shaders/cbod-v1
SHADER_DIRS+=	dithering/shaders/gdapt
SHADER_DIRS+=	dithering/shaders/mdapt
SHADER_DIRS+=	dithering/shaders/mdapt/passes
SHADER_DIRS+=	eagle
SHADER_DIRS+=	eagle/shaders
SHADER_DIRS+=	handheld
SHADER_DIRS+=	handheld/console-border
SHADER_DIRS+=	handheld/console-border/resources
SHADER_DIRS+=	handheld/console-border/shader-files
SHADER_DIRS+=	handheld/shaders
SHADER_DIRS+=	handheld/shaders/color
SHADER_DIRS+=	handheld/shaders/gameboy
SHADER_DIRS+=	handheld/shaders/gameboy/resources
SHADER_DIRS+=	handheld/shaders/gameboy/resources/sample-bgs
SHADER_DIRS+=	handheld/shaders/gameboy/resources/sample-palettes
SHADER_DIRS+=	handheld/shaders/gameboy/shader-files
SHADER_DIRS+=	handheld/shaders/lcd-cgwg
SHADER_DIRS+=	handheld/shaders/lcd-shader
SHADER_DIRS+=	handheld/shaders/lcd-shader/backup
SHADER_DIRS+=	handheld/shaders/lcd-shader/backup-2
SHADER_DIRS+=	handheld/shaders/lcd-shader/backup-3
SHADER_DIRS+=	hqx
SHADER_DIRS+=	hqx/resources
SHADER_DIRS+=	hqx/shader-files
SHADER_DIRS+=	hqx/single-pass
SHADER_DIRS+=	hqx/single-pass/shader-files
SHADER_DIRS+=	misc
SHADER_DIRS+=	motionblur
SHADER_DIRS+=	motionblur/shaders
SHADER_DIRS+=	nedi
SHADER_DIRS+=	nedi/shaders
SHADER_DIRS+=	nnedi3
SHADER_DIRS+=	nnedi3/shaders
SHADER_DIRS+=	ntsc
SHADER_DIRS+=	ntsc/shaders
SHADER_DIRS+=	ntsc/shaders/artifact-colors
SHADER_DIRS+=	ntsc/shaders/ntsc-vcr
SHADER_DIRS+=	omniscale
SHADER_DIRS+=	omniscale/shaders
SHADER_DIRS+=	pal
SHADER_DIRS+=	pal/shaders
SHADER_DIRS+=	presets
SHADER_DIRS+=	procedural
SHADER_DIRS+=	reshade
SHADER_DIRS+=	reshade/shaders
SHADER_DIRS+=	reshade/shaders/LUT
SHADER_DIRS+=	retro
SHADER_DIRS+=	retro/shaders
SHADER_DIRS+=	sabr
SHADER_DIRS+=	sabr/shaders
SHADER_DIRS+=	scalefx
SHADER_DIRS+=	scalefx/shaders
SHADER_DIRS+=	scalehq
SHADER_DIRS+=	scalehq/shaders
SHADER_DIRS+=	scalenx
SHADER_DIRS+=	scalenx/shaders
SHADER_DIRS+=	sharpen
SHADER_DIRS+=	sharpen/shaders
SHADER_DIRS+=	test
SHADER_DIRS+=	test/nonfunctional
SHADER_DIRS+=	test/nonfunctional/shaders
SHADER_DIRS+=	test/nonfunctional/shaders/xbr-mlv4-multipass
SHADER_DIRS+=	windowed
SHADER_DIRS+=	windowed/shaders
SHADER_DIRS+=	xbr
SHADER_DIRS+=	xbr/shaders
SHADER_DIRS+=	xbr/shaders/2xBR-multipass
SHADER_DIRS+=	xbr/shaders/super-xbr
SHADER_DIRS+=	xbr/shaders/xbr-hybrid
SHADER_DIRS+=	xbr/shaders/xbr-lv3-multipass
SHADER_DIRS+=	xbrz
SHADER_DIRS+=	xbrz/shaders
SHADER_DIRS+=	xsal
SHADER_DIRS+=	xsal/shaders
SHADER_DIRS+=	xsoft
SHADER_DIRS+=	xsoft/shaders

INSTALLATION_DIRS+=	share/libretro/shaders
.for i in ${SHADER_DIRS}
INSTALLATION_DIRS+=	share/libretro/shaders/${i}
.endfor

do-install:
.for type in glsl glslp
	if ${LS} -1 ${WRKSRC} | ${GREP} -q .${type}$$ ; then \
	    ${INSTALL_DATA} ${WRKSRC}/*.${type} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders ; \
	fi
.endfor
.for dir in ${SHADER_DIRS}
.  for type in glsl glslp md png
	if ${LS} -1 ${WRKSRC}/${dir} | ${GREP} -q .${type}$$ ; then \
	    ${INSTALL_DATA} ${WRKSRC}/${dir}/*.${type} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/${dir} ; \
	fi
.  endfor
.endfor

.include "../../mk/bsd.pkg.mk"
