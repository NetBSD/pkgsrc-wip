# $NetBSD$

DISTNAME=	wheel-0.26.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://bitbucket.org/pypa/wheel/
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wheel \
	      ${DESTDIR}${PREFIX}/bin/wheel-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
