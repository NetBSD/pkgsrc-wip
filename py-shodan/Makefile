# $NetBSD: Makefile,v 1.13 2023/06/06 12:42:49 riastradh Exp $

DISTNAME=	shodan-1.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shodan/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/achillean/shodan-python
COMMENT=	Python library and command-line utility for Shodan
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=44.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-plugins-[0-9]*:../../devel/py-click-plugins
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-xlsxwriter-[0-9]*:../../textproc/py-xlsxwriter

# Several dependencies incompatible with Python 2.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/shodan ${DESTDIR}${PREFIX}/bin/shodan${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
