# $NetBSD$
DISTNAME=		cinelerra-gg-${DISTVERSION}-${DISTREVISION}
DISTVERSION=		5.1-20241228
#DISTVERSIONSUFFIX=	-${REV:C/(.......).*/\1/}
DISTREVISION=		1
CATEGORIES=		multimedia
REV=			c92ff91450d5a66e8bef72a103ae13002144953c # git revision
MASTER_SITES=		https://git.cinelerra-gg.org/git?p=goodguy/cinelerra.git;a=snapshot;h=${REV};sf=tgz;dummy=/
DISTFILES=		cinelerra-c92ff91.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Professional video editing and compositing environment
HOMEPAGE=	https://www.cinelerra-gg.org/

LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64 NetBSD-*-i386

#CHECK_PORTABILITY_SKIP=cinelerra-5.1/configure

USE_LANGUAGES=		c c++

USE_TOOLS+=	bash:run pkg-config

REPLACE_PERL=cinelerra-5.1/doc/ContextManual.pl

USE_TOOLS+=	pkg-config gmake aclocal autoconf automake makeinfo
GNU_CONFIGURE=	yes

REPLACE_BASH=   cinelerra-5.1/inst.sh cinelerra-5.1/doc/RenderMux.sh

CFLAGS+=		-fpermissive

MAKE_ENV=		BSD=1
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
CONFIGURE_ARGS+=	--with-xxf86vm
CONFIGURE_ARGS+=	--without-ladspa-build
CONFIGURE_ARGS+=	--without-shuttle
CONFIGURE_ARGS+=	--without-libdpx
CONFIGURE_ARGS+=	--without-shuttle-usb
CONFIGURE_ARGS+=	--without-x10tv
CONFIGURE_ARGS+=	--without-wintv
CONFIGURE_ARGS+=	--with-lv2
CONFIGURE_ARGS+=	--without-libzmpeg
CONFIGURE_ARGS+=	--without-commercial
CONFIGURE_ARGS+=	--without-thirdparty
CONFIGURE_ARGS+=	--with-jobs=${MAKE_JOBS:U1}

WRKSRC=			${WRKDIR}/cinelerra-${REV:C/(.......).*/\1/}
CONFIGURE_DIRS=		${WRKSRC}/cinelerra-5.1

post-patch:

#	# fix lipng for lpng16
	cd ${CONFIGURE_DIRS}/guicast && sed -i -e 's|-lz|-lz -lpng16|' Makefile
	# remove thirdparty/src for more space
	rm -rf ${CONFIGURE_DIRS}/thirdparty/src/*
#	# correct the bash interpreter path
#	cd ${CONFIGURE_DIRS}/cinelerra && sed -i  -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
#		../configure.ac bdcreate.C dvdcreate.C shbtnprefs.C

pre-configure:
	cd ${CONFIGURE_DIRS}  \
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash ./autogen.sh

CONFIG_SHELL=	bash

do-configure: # need MAKE_ENV esp BSD=1
	cd ${CONFIGURE_DIRS}  && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/bash configure ${CONFIGURE_ARGS}

do-build:
	cd ${CONFIGURE_DIRS} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS}

do-install:
	cd ${CONFIGURE_DIRS} && ${SETENV} ${MAKE_ENV} gmake ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install


.include "../../lang/python/tool.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/libdeflate/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
