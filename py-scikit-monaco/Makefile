# $NetBSD: Makefile,v 1.1 2014/02/05 20:03:52 jihbed Exp $

DISTNAME=	scikit-monaco-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	scikit_monaco-${PKGVERSION}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/scikit-monaco/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/scikit-monaco
COMMENT=	Python modules for Monte Carlo integration
LICENSE=	modified-bsd


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
