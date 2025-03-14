# $NetBSD$

DISTNAME=	mtp-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CameronLonsdale/mtp
COMMENT=	Many-Time Pad Interactive
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-urwid>0:../../devel/py-urwid

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mtp ${DESTDIR}${PREFIX}/bin/mtp${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
