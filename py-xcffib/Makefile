# $NetBSD$

DISTNAME=	xcffib-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xcffib/}

HOMEPAGE=	https://pypi.org/project/xcffib/
COMMENT=	Python binding to the X Window System protocol via libxcb
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
