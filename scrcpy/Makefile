# $NetBSD$

DISTNAME=	scrcpy-4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Genymobile/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Genymobile/scrcpy/
COMMENT=	Display and control your Android device
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config bash

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	android-tools>=34:../../wip/android-tools

VERSION=		${DISTNAME:S/scrcpy-//}
SERVERFILE=		scrcpy-server-v${VERSION}
DISTFILES=		${DEFAULT_DISTFILES} ${SERVERFILE}
SERVERTGTFILE=		${WRKSRC}/server/scrcpy-server
SITES.${SERVERFILE}=	${MASTER_SITE_GITHUB:=Genymobile/scrcpy/releases/download/v${VERSION}/}
MESON_ARGS+=		-Dprebuilt_server=${SERVERTGTFILE}

post-extract:
	mv ${WRKDIR}/${SERVERFILE} ${SERVERTGTFILE}

.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/SDL3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
