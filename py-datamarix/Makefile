# $NetBSD$

DISTNAME=	python-datamatrix-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datamatrix/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/smathot/python-datamatrix
COMMENT=	Intuitive, Pythonic way to work with tabular data
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/python-datamatrix-0.3.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
