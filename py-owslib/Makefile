# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	OWSLib-0.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OWSLib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://geopython.github.io/OWSLib
COMMENT=	OGC Web Service utility library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
