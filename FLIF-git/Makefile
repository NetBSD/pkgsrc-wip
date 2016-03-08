# $NetBSD$

DISTNAME=	FLIF-0.1alpha
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=FLIF-hub/}

GIT_REPOSITORIES=	flif
GIT_REPO.flif=		https://github.com/FLIF-hub/flif.git
WRKSRC=			${WRKDIR}/${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flif.info/
COMMENT=	Free Lossless Image Format
LICENSE=	gnu-lgpl-v3

BUILD_DIRS=	src
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
