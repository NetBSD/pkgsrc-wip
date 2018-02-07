# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:43 thomasklausner Exp $

DISTNAME=	SphinxReport-2.0
PKGNAME=	${PYPKGPREFIX}-sphinxreport-2.0
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SphinxReport/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/sphinx-report/
COMMENT=	Report generator in python based on Sphinx and matplotlib
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=1.6.2:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
