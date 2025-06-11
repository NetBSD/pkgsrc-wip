# $NetBSD$

DISTNAME=	scrcpy-3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Genymobile/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Genymobile/scrcpy/
COMMENT=	Display and control your Android device
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config bash

WRKSRC=	${WRKDIR}/${DISTNAME}

DEPENDS+=	android-tools-adb-[0-9]*:../../devel/android-tools-adb

SERVERFILE=		scrcpy-server-v3.2
DISTFILES=		${DEFAULT_DISTFILES} ${SERVERFILE}
SERVERTGTFILE=		${WRKSRC}/server/scrcpy-server
SITES.${SERVERFILE}=	${MASTER_SITE_GITHUB:=Genymobile/}/scrcpy/releases/download/v3.2/
MESON_ARGS+=		-Dprebuilt_server=${SERVERTGTFILE}

post-extract:
	mv ${WRKDIR}/${SERVERFILE} ${SERVERTGTFILE}

.include "../../devel/meson/build.mk"
.include "../../devel/cmake/build.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
