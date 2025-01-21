# $NetBSD: Makefile,v 1.96 2025/01/19 16:29:06 leot Exp $

DISTNAME=	pywhat-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pywhat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bee-san/pyWhat/
COMMENT=	Identify what something is
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-rich>=11.0.0:../../comms/py-rich

REPLACE_PYTHON+=	pywhat/*.py

USE_LANGUAGES=			# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pywhat ${DESTDIR}${PREFIX}/bin/pywhat${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/what ${DESTDIR}${PREFIX}/bin/what${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
