# $NetBSD$

DISTNAME=	GoreUtilities-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GoreUtilities/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/gorelab/goreutilities/
COMMENT=	Some utility functions useful for GoreLab members
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.17.1:../../math/py-pandas

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
