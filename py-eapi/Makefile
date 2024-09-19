# $NetBSD$

DISTNAME=	pyeapi-0.8.0
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyeapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arista-eosplus/${PKGBASE}
COMMENT=	Library for Arista's eAPI command API implementation
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
