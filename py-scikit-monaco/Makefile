# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	scikit-monaco-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	scikit_monaco-${PKGVERSION}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/scikit-monaco/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/scikit-monaco
COMMENT=	Python modules for Monte Carlo integration
LICENSE=	modified-bsd


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
