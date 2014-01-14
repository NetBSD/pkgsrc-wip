# $NetBSD: Makefile,v 1.1 2014/01/14 10:37:14 jihbed Exp $

DISTNAME=	py-sphviewer-0.88
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	graphics math python
MASTER_SITES=	https://pypi.python.org/packages/source/p/py-sphviewer/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://code.google.com/p/py-sphviewer/
COMMENT=	Framework for rendering particle simulations
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
