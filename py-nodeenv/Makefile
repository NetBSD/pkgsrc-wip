# $NetBSD$

DISTNAME=	nodeenv-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nodeenv/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://ekalinin.github.io/nodeenv/
COMMENT=	Node.js virtual environment
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} nodeenv nodeenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
