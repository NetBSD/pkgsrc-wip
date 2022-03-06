# $NetBSD$

DISTNAME=	semver-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semver/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-semver/python-semver
COMMENT=	Python package to work with Semantic Versioning
LICENSE=	modified-bsd

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pysemver ${DESTDIR}${PREFIX}/bin/pysemver-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
