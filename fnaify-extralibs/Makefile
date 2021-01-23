# $NetBSD$

GITHUB_PROJECT=	fnaify-extralibs
GITHUB_TAG=	0.1
DISTNAME=	0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=rfht/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rfht/fnaify-extralibs/
COMMENT=	Additional libraries for running games with fnaify
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/fnaify-extralibs-0.1

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS+=	lib

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
