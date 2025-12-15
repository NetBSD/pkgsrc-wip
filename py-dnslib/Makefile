# $NetBSD$

DISTNAME=	dnslib-0.9.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnslib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paulc/dnslib
COMMENT=	Python library to encode/decode DNS wire-format packets
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
