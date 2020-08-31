# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	easydev-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easydev/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://packages.python.org/easydev/
COMMENT=	Common utilities to ease the development of Python packages
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
