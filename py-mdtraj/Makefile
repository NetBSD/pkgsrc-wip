# $NetBSD$

DISTNAME=	mdtraj-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://pypi.python.org/packages/cd/9f/027fa58d4e93dd3d700e22d5766961c970f6882c2bffd33daef55219d078/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mdtraj.org/
COMMENT=	The analysis of molecular dynamics trajectories
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/mdtraj-1.8.0

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
