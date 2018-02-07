# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:46 thomasklausner Exp $

DISTNAME=	py-sphviewer-0.88
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	graphics math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-sphviewer/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://code.google.com/p/py-sphviewer/
COMMENT=	Framework for rendering particle simulations
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
