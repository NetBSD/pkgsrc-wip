# $NetBSD$

DISTNAME=	scrcpy-1.24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Genymobile/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Genymobile/scrcpy/
COMMENT=	Display and control your Android device
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config bash
USE_CMAKE=	yes

SERVERFILE=	scrcpy-server-v1.24
DISTFILES=	${DEFAULT_DISTFILES} ${SERVERFILE}
SERVERTGTFILE=	${WRKSRC}/server/scrcpy-server
ICON_THEMES=	yes

DEPENDS+=	android-tools-adb-[0-9]*:../../wip/android-tools-adb

SITES.${SERVERFILE}=	${MASTER_SITE_GITHUB:=Genymobile/}/scrcpy/releases/download/v1.24/scrcpy-server-v1.24/

MESON_ARGS+=	-Dprebuilt_server=${SERVERTGTFILE}

post-extract:
	mv ${WRKDIR}/${SERVERFILE} ${SERVERTGTFILE}

.include "../../devel/meson/build.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
