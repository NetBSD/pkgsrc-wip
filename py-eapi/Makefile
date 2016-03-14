# $NetBSD$

DISTNAME=	pyeapi-0.6.0
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=arista-eosplus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fooelisa/${PKGBASE}
COMMENT=	Library for Arista's eAPI command API implementation
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
