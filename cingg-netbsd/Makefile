# $NetBSD$
DISTNAME=		cinelerra-gg-${DISTVERSION}-${DISTREVISION}
DISTVERSION=		5.1-20240703
DISTVERSIONSUFFIX=	-${REV:C/(.......).*/\1/}
DISTREVISION=		3
CATEGORIES=		multimedia
REV=			73eb8f8d040d50f33db883d12adaaf33a2d1520c # git revision
MASTER_SITES=		https://git.cinelerra-gg.org/git?p=goodguy/cinelerra.git;a=snapshot;h=${REV};sf=tgz;dummy=/
#MASTER_SITES=		https://www.cinelerra-gg.org/download/pkgs/src/cin_$DISTVERSION-src.tgz
DISTFILES=		cinelerra-gg-5.1-20240703-73eb8f8d.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Professional video editing and compositing environment
HOMEPAGE=	https://www.cinelerra-gg.org/

LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-amd64 NetBSD-*-i386

USE_LANGUAGES=		c c++

USE_TOOLS+=	bash:run

#EXTRA_PATCHES=	${BUILD_WRKSRC}/blds/bsd.patch:-p1



#USES=		perl5 autoreconf aclocal gettext-runtime gettext-tools gmake iconv:wchar_t \
#		jpeg localbase makeinfo python:3.9,build shebangfix xorg

SHEBANG_GLOB=	*.sh *.bld
SHEBANG_FILES=	cinelerra-5.1/doc/ContextManual.pl
USE_TOOLS+=	gmake aclocal autoconf automake makeinfo
GNU_CONFIGURE=	yes

#USE_XORG=	x11 xau xdmcp xext xfixes xft xinerama xv

#CPPFLAGS+=		-I/usr/X11R7/include
#CPPFLAGS+=		-I/usr/pkg/include/freetype2

CXXFLAGS+=		-I/usr/X11R7/include
CXXFLAGS+=		-I/usr/pkg/include/freetype2

CFLAGS+=		-fpermissive

MAKE_ENV=		C_INCLUDE_PATH=${PREFIX}/include:/usr/X11R7/include CPLUS_INCLUDE_PATH=${PREFIX}/include:${PREFIX}/include/uuid:${PREFIX}/include/ffmpeg6:/usr/X11R7/include:/usr/pkg/include/freetype2:/usr/pkg/include/OpenEXR:/usr/pkg/include/Imath  LIBRARY_PATH=${PREFIX}/lib:/usr/X11R7/lib:${PREFIX}/lib/ffmpeg6 BSD=1
CONFIGURE_ARGS+=	--disable-static-build
CONFIGURE_ARGS+=	--disable-lame
CONFIGURE_ARGS+=	--disable-twolame
CONFIGURE_ARGS+=	--with-oss
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-firewire
CONFIGURE_ARGS+=	--without-dv
CONFIGURE_ARGS+=	--without-dvb
CONFIGURE_ARGS+=	--with-openexr
CONFIGURE_ARGS+=	--without-video4linux2
CONFIGURE_ARGS+=	--without-xxf86vm
CONFIGURE_ARGS+=	--without-ladspa-build
CONFIGURE_ARGS+=	--without-shuttle
CONFIGURE_ARGS+=	--without-libdpx
CONFIGURE_ARGS+=	--without-shuttle-usb
CONFIGURE_ARGS+=	--without-x10tv
CONFIGURE_ARGS+=	--without-wintv
CONFIGURE_ARGS+=	--without-lv2
CONFIGURE_ARGS+=	--without-libzmpeg
CONFIGURE_ARGS+=	--without-commercial
CONFIGURE_ARGS+=	--without-thirdparty
CONFIGURE_ARGS+=	--with-jobs=4

WRKSRC=			${WRKDIR}/cinelerra-${REV:C/(.......).*/\1/}
CONFIGURE_DIRS=		${WRKSRC}/cinelerra-5.1
#BUILD_DIRS=		${WRKSRC}/cinelerra-${DISTVERSION:C/-.*//}
#INSTALL_DIRS=		${BUILD_WRKSRC}

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
#	# fix lipng for lpng16
	cd ${CONFIGURE_DIRS}/guicast && sed -i -e 's|-lz|-lz -lpng16|' Makefile
	# remove thirdparty/src for more space
	rm -rf ${CONFIGURE_DIRS}/thirdparty/src/*
#	# correct the bash interpreter path
	cd ${CONFIGURE_DIRS}/cinelerra && sed -i  -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		../configure.ac bdcreate.C dvdcreate.C shbtnprefs.C

pre-configure:
	cd ${CONFIGURE_DIRS}  \
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash ./autogen.sh

CONFIG_SHELL=	bash

do-configure: # naeed MAKE_ENV esp BSD=1
	cd ${CONFIGURE_DIRS}  && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash configure ${CONFIGURE_ARGS}

do-build:
	cd ${CONFIGURE_DIRS} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS}

do-install:
	cd ${CONFIGURE_DIRS} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install


.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/x264/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../multimedia/libvdpau/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
#.include "../../graphics/openexr/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
