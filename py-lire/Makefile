# $NetBSD: Makefile,v 1.1 2014/07/26 12:38:07 jihbed Exp $

DISTNAME=	pylire-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pylire/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/fish2000/pylire/
COMMENT=	Python/Cython port of Lire image processing algorithms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py

USE_LANGUAGES=	c

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"