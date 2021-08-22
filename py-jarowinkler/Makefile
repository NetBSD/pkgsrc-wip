# $NetBSD$

DISTNAME=	jaroWwinkler-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	JaroWinkler
GITHUB_TAG=	pypi-v2.0.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=richmilne/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/richmilne/JaroWinkler.git
COMMENT=	Standard versions of the Jaro-Winkler functions
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=  27

WRKSRC=	${WRKDIR}/JaroWinkler-pypi-v2.0.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
