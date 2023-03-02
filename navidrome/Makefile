# $NetBSD$

DISTNAME=	navidrome-0.49.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=navidrome/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/navidrome/navidrome/
COMMENT=	Modern Music Server and Streamer compatible with Subsonic/Airsonic
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/navidrome \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../lang/nodejs16/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
