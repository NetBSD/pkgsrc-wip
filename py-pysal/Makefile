# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	PySAL-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py/py/tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySAL/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysal.org
COMMENT=	Python Spatial Analysis Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
