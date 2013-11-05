# $NetBSD: Makefile,v 1.1 2013/11/05 17:49:07 jihbed Exp $

DISTNAME=	SphinxReport-2.0
PKGNAME=        ${PYPKGPREFIX}-sphinxreport-2.0
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/S/SphinxReport/
FETCH_USING=    curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/sphinx-report/
COMMENT=	Report generator in python based on Sphinx and matplotlib
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7:../../databases/py-sqlalchemy
DEPENDS+=    	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=1.6.2:../../wip/py-openpyxl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
