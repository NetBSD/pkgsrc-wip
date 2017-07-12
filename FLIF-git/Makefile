# $NetBSD$

DISTNAME=	FLIF-0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=FLIF-hub/}

GIT_REPOSITORIES=	flif
GIT_REPO.flif=		git://github.com/FLIF-hub/flif.git
WRKSRC=			${WRKDIR}/flif

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flif.info/
COMMENT=	Free Lossless Image Format
LICENSE=	gnu-lgpl-v3 AND apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../graphics/png/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
