# $NetBSD: Makefile,v 1.4 2014/02/02 21:15:07 jihbed Exp $

DISTNAME=	lsqfit-4.6.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lsqfit/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	  https://github.com/gplepage/lsqfit.git
COMMENT=	Utilities for nonlinear least-squares fits
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
