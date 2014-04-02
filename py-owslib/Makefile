# $NetBSD: Makefile,v 1.2 2014/04/02 17:10:59 asau Exp $

DISTNAME=	OWSLib-0.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/O/OWSLib/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	 https://geopython.github.io/OWSLib
COMMENT=	OGC Web Service utility library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-elementtree

.include "../../lang/python/egg.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
