# $NetBSD$

CATEGORIES=	games

COMMENT=	Strategy game engine for early Westwood games such as C&C: Red Alert
LICENSE=	gnu-gpl-v3

VERSION=	20231010
PKGNAME=	OpenRA-${VERSION}
DISTNAME=	release-${VERSION}
GITHUB_PROJECT=	OpenRA
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenRA/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	tm@core.io
HOMEPAGE=	https://github.com/OpenRA/OpenRA/

USE_TOOLS+=	gmake unzip

MAKE_FLAGS+=		prefix=${DESTDIR}${PREFIX}
MAKE_FLAGS+=		mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}
BUILD_MAKE_FLAGS+=	RUNTIME=mono
BUILD_MAKE_FLAGS+=	TARGETPLATFORM=unix-generic
#BUILD_TARGET=		all

#DEPENDS+=	libgdiplus-[0-9]*:../../graphics/libgdiplus
#DEPENDS+=	lua51-[0-9]*:../../lang/lua51

pre-configure:
	cd ${WRKSRC} && gmake version VERSION="${DISTNAME}"

do-install:
	cd ${WRKSRC} && \
	gmake prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
	install install-linux-scripts install-man-page


.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
