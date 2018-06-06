# $NetBSD$

DISTNAME=	pystatsd-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystatsd/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sivy/py-statsd
COMMENT=	Client and server implementation of statsd
LICENSE=	2-clause-bsd

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pystatsd-server \
		${DESTDIR}${PREFIX}/bin/pystatsd-server${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
