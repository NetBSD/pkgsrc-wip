# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:42 thomasklausner Exp $

DISTNAME=	gvar-4.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gvar/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/gplepage/lsqfit.git
COMMENT=	Utilities for manipulating Gaussian random variables
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
