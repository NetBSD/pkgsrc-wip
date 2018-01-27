# $NetBSD$

DISTNAME=	spams-python-v2.5-svn2014-07-04
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	math
MASTER_SITES=	http://spams-devel.gforge.inria.fr/hitcounter2.php?file=33816/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spams-devel.gforge.inria.fr/
COMMENT=	SPArse Modeling Software for solving various sparse estimation
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

WRKSRC=		${WRKDIR}/spams-python

USE_LANGUAGES=	c c++

.include "../../lang/python/distutils.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
