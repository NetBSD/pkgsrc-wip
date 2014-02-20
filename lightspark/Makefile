# $NetBSD: Makefile,v 1.2 2014/02/20 13:57:06 thomasklausner Exp $

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
GCC_REQD+=	4.6
AUTO_MKDIRS=	yes
EGDIR=		${PREFIX}/share/examples/lightspark
CMAKE_ARGS+=	-DGNASH_EXE_PATH:STRING="${PREFIX}/bin/gnash"

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/xdg ${DESTDIR}${EGDIR}; \
	${RMDIR} ${DESTDIR}${PREFIX}/etc

CONF_FILES=	${EGDIR}/xdg/lightspark.conf ${PKG_SYSCONFDIR}/xdg/lightspark.conf

BUILDLINK_API_DEPENDS.xz+=	xz>=5.0.5
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../wip/llvm-rtlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
