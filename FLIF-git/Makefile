# $NetBSD$

DISTNAME=	FLIF-0.3
CATEGORIES=	graphics
GIT_REPO=	git://github.com/FLIF-hub/flif.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flif.info/
COMMENT=	Free Lossless Image Format
LICENSE=	gnu-lgpl-v3 AND apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../graphics/png/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
