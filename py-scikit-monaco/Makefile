# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:41 thomasklausner Exp $

DISTNAME=	scikit-monaco-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-monaco/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/scikit-monaco
COMMENT=	Python modules for Monte Carlo integration
LICENSE=	modified-bsd


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
