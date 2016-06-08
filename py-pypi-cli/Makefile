# $NetBSD: Makefile,v 1.1 2015/02/14 13:24:00 jihbed Exp $

DISTNAME=	pypi-cli-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypi-cli/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloria/pypi-cli
COMMENT=	Command-line interface to the Python Package Index
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=3.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
