# $NetBSD$

DISTNAME=	pyeapi-0.6.0
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	net python
MASTER_SITES=	-https://github.com/arista-eosplus/pyeapi/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fooelisa/${PKGBASE}
COMMENT=	Library for Arista's eAPI command API implementation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=	35 34 33 27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
