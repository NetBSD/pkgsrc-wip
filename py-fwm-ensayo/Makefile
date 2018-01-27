# $NetBSD: Makefile,v 1.1 2014/07/15 09:52:24 jihbed Exp $

DISTNAME=	fwm_ensayo-0.1.1
PKGNAME=	${PYPKGPREFIX}-fwm-ensayo-0.1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fwm_ensayo/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/fwm_ensayo/
COMMENT=	Fortran package to work with watersheds and do hydrologic
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy	

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
