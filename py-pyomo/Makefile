# $NetBSD$

GITHUB_PROJECT=	pyomo
GITHUB_TAG=	refs/tags/6.8.0
DISTNAME=	6.8.0
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pyomo/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pyomo/pyomo/
COMMENT=	OO algebraic modeling language in Python for structured optimization
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
