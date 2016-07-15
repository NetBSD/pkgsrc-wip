# $NetBSD: Makefile,v 1.2 2014/07/26 12:39:03 jihbed Exp $

DISTNAME=	pylire-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylire/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/fish2000/pylire/
COMMENT=	Python/Cython port of Lire image processing algorithms
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-numexpr-[0-9]*:../../math/py-numexpr

USE_LANGUAGES=	c

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
