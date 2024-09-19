# $NetBSD$

DISTNAME=	mininet-2.3.0.dev6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mininet/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://mininet.org/
COMMENT=	Process-based OpenFlow emulator
LICENSE=	modified-bsd

post-extract:
	${MV} ${WRKSRC}/bin/mn	${WRKSRC}/bin/mn${PYVERSSUFFIX}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
