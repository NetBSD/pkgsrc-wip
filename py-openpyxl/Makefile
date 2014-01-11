# $NetBSD: Makefile,v 1.2 2014/01/11 20:52:09 jihbed Exp $

DISTNAME=	openpyxl-1.8.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/o/openpyxl/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://openpyxl.readthedocs.org/
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files
LICENSE=	mit

WRKSRC=		${WRKDIR}/openpyxl-1.8.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
