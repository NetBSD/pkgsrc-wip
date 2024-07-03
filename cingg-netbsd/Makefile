# $NetBSD$
DISTNAME=	cinelerra-gg-${DISTVERSION}-${DISTREVISION}
DISTVERSION=	5.1-2024110703
DISTVERSIONSUFFIX=	-${REV:C/(.......).*/\1/}
DISTREVISION=	1
CATEGORIES=	multimedia
REV=		73eb8f8d040d50f33db883d12adaaf33a2d1520c # git revision
MASTER_SITES=	https://git.cinelerra-gg.org/git?p=goodguy/cinelerra.git;a=snapshot;h=${REV};sf=tgz;dummy=/
#MASTER_SITES=	https://www.cinelerra-gg.org/download/pkgs/src/cin_$DISTVERSION-src.tgz
DISTFILES=	cinelerra-gg-5.1-20240703-73eb8f8d.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Professional video editing and compositing environment
WWW=		https://www.cinelerra-gg.org/

LICENSE=	gnu-gpl-v2
LICENSE_FILE=	${BUILD_WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not designed for other architectures

USE_LANGUAGES=		c c++

BUILD_DEPENDS=	bash:../../shells/bash \
		nasm:../../devel/nasm \
		yasm:../../devel/yasm \
		libdv*:../../multimedia/libdv \
		mjpegtools*:../../multimedia/mjpegtools
DEPENDS=	flac:../../audio/flac \
		alsa-lib*:../../audio/alsa-lib \
		ffmpeg6*:../../multimedia/ffmpeg6 \
		fftw:../../math/fftw \
		giflib*:../../graphics/giflib \
		openexr*:../../graphics/openexr \
		libogg*:../../multimedia/libogg \
		openjpeg*:../../graphics/openjpeg \
		libopus*:../../audio/libopus \
		png-1.6*:../../graphics/png \
		libsndfile*:../../audio/libsndfile \
		libtheora*:../../multimedia/libtheora \
		tiff*:../../graphics/tiff \
		libvorbis*:../../audio/libvorbis \
		libvpx*:../../multimedia/libvpx \
		libwebp*:../../graphics/libwebp \
		x264*:../../multimedia/x264 \
		x265*:../../multimedia/x265 \
		imath*:../../math/imath \
		mjpegtools*:../../multimedia/mjpegtools \
		libaom*:../../multimedia/libaom \
		dav1d*:../../multimedia/dav1d \
		jbigkit*:../../graphics/jbigkit \
		libvdpau*:../../multimedia/libvdpau \
		libva*:../../multimedia/libva \
		pulseaudio*:../../audio/pulseaudio 
RUN_DEPENDS=	bash:../../shells/bash

#EXTRA_PATCHES=	${BUILD_WRKSRC}/blds/bsd.patch:-p1



USES=		perl5 autoreconf aclocal gettext-runtime gettext-tools gmake iconv:wchar_t \
		jpeg localbase makeinfo python:3.9,build shebangfix xorg
SHEBANG_GLOB=	*.sh *.bld
SHEBANG_FILES=	cinelerra-5.1/doc/ContextManual.pl
USE_TOOLS+=	gmake aclocal autoconf automake makeinfo
GNU_CONFIGURE=	yes
USE_XORG=	x11 xau xdmcp xext xfixes xft xinerama xv

#CPPFLAGS+=		-I/usr/X11R7/include
#CPPFLAGS+=		-I/usr/pkg/include/freetype2

CXXFLAGS+=		-I/usr/X11R7/include
CXXFLAGS+=		-I/usr/pkg/include/freetype2

CFLAGS+=		-fpermissive
LDFLAGS+=		-lpng16

MAKE_ENV=	C_INCLUDE_PATH=${LOCALBASE}/include:/usr/X11R7/include CPLUS_INCLUDE_PATH=${LOCALBASE}/include:${LOCALBASE}/include/uuid:${LOCALBASE}/include/ffmpeg6:/usr/X11R7/include:/usr/pkg/include/freetype2  LIBRARY_PATH=${LOCALBASE}/lib:/usr/X11R7/lib:${LOCALBASE}/lib/ffmpeg6 BSD=1
CONFIGURE_ARGS=	--disable-static-build --disable-lame --disable-twolame \
		--with-oss --without-alsa \
		--without-firewire --without-dv --without-dvb --without-openexr \
		--without-video4linux2 --without-xxf86vm --without-ladspa-build \
		--without-shuttle --without-libdpx --without-shuttle-usb \
		--without-x10tv --without-wintv --without-lv2 \
		--without-libzmpeg --without-commercial --without-thirdparty \
		--with-jobs=4
#CFLAGS+=	-DFFMPEG3
BINARY_ALIAS=	make=gmake
BINARY_ALIAS=	python=python3.9


WRKSRC=			${WRKDIR}/cinelerra-${REV:C/(.......).*/\1/}
AUTORECONF_WRKSRC=	${BUILD_WRKSRC}
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
BUILD_WRKSRC=		${WRKSRC}/cinelerra-${DISTVERSION:C/-.*//}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

DATADIR=		${PREFIX}/share/cin

OPTIONS_DEFINE=		LV2 OPENGL
OPTIONS_DEFAULT=	LV2 OPENGL
OPTIONS_SUB=		yes

LV2_DESC=		Use LV2 plugins
LV2_CONFIGURE_WITH=	lv2
LV2_USES=		gnome pkg-config
LV2_USE=		GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
LV2_CFLAGS=		-I${LOCALBASE}/include/lilv-0 -I${LOCALBASE}/include/suil-0
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libserd-0.so:devel/serd \
			libsord-0.so:devel/sord \
			libsratom-0.so:audio/sratom \
			libsuil-0.so:audio/suil

OPENGL_CONFIGURE_WITH=	gl
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu

post-patch:
#	# the patch recommended by the upstream
#	@cd ${CONFIGURE_WRKSRC}/ffmpeg && \
#		for f in `grep -lr libfdk_ .`; do ${REINPLACE_CMD} -e 's/libfdk_//' -i '' $$f; done;
	# fix lipng for lpng16
	@cd ${CONFIGURE_WRKSRC}/guicast && sed -i -e 's|-lz|-lz -lpng16|' Makefile
	# remove thirdparty/src for more space
	@rm -rf ${CONFIGURE_WRKSRC}/thirdparty/src/*
#	# correct the bash interpreter path
	@cd ${CONFIGURE_WRKSRC}/cinelerra && sed -i  -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		../configure.ac bdcreate.C dvdcreate.C shbtnprefs.C

pre-configure:
	@cd ${CONFIGURE_WRKSRC}  \
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash ./autogen.sh

do-configure: # configure needs bash
	@cd ${CONFIGURE_WRKSRC}  && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash configure ${CONFIGURE_ARGS}
	
do-build:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS}
	
do-install:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install

.include "../../mk/bsd.pkg.mk"
.include "../../mk/x11.builtin.mk"
#.include "../../graphics/openexr/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"