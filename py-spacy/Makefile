# $NetBSD$

GITHUB_PROJECT=	spaCy
PKGVERSION=	3.0.5
DISTNAME=	${GITHUB_PROJECT}-v${PKGVERSION}


CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
DIST_SUBDIR=	${GITHUB_PROJECT}-${PKGVERSION}
WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/spaCy/
COMMENT=	Short description of the package
LICENSE=	mit

USE_TOOLS+=     gmake perl:run pkg-config

# url2pkg-marker (please do not remove this line.)


#.include "../../devel/py-setuptools/buildlink3.mk"
.include "../../wip/py-cymem/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
