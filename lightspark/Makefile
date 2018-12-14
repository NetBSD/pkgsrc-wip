# $NetBSD: Makefile,v 1.11 2015/03/04 19:48:16 tnn2 Exp $

DISTNAME=	lightspark-0.7.2
CATEGORIES=	multimedia
MASTER_SITES=	https://launchpad.net/lightspark/trunk/lightspark-0.7.2/+download/

MAINTAINER=	nathanialsloss@yahoo.com.au
LICENSE=	gnu-gpl-v3
HOMEPAGE=	https://launchpad.net/lightspark/
COMMENT=	GPL AMV2 Flash player and plugin

DEPENDS+=	xdg-utils>=1.0:../../misc/xdg-utils

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
GCC_REQD+=	4.6
AUTO_MKDIRS=	yes
EGDIR=		${PREFIX}/share/examples/lightspark
CMAKE_ARGS+=	-DGNASH_EXE_PATH:STRING="${PREFIX}/bin/gnash"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-stdlib=libc++
CXXFLAGS+=	-std=c++0x
.endif

pre-configure:
	${LN} -s ${LLVM_CONFIG_PATH} ${TOOLS_DIR}/bin/llvm-config

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/xdg ${DESTDIR}${EGDIR} && \
	${RMDIR} ${DESTDIR}${PREFIX}/etc

CONF_FILES=	${EGDIR}/xdg/lightspark.conf ${PKG_SYSCONFDIR}/xdg/lightspark.conf

DEPENDS+=	gnash>=0.8.10:../../multimedia/gnash
BUILD_DEPENDS+=	nasm>=2.10:../../devel/nasm
BUILDLINK_API_DEPENDS.xz+=	xz>=5.0.5
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/libLLVM34/buildlink3.mk"
.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
