# $NetBSD: Makefile,v 1.1 2014/06/20 10:46:03 jihbed Exp $

DISTNAME=	pseudopy-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pseudopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/andrenarchy/pseudopy
COMMENT=	Compute and visualize pseudospectra of matrices
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-shapely>=1.3.2:../../wip/py-shapely

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
