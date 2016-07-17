# $NetBSD$

DISTNAME=	chainer-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/8f/e0/b1860a9e79ed84831eed6320c3b810d44f99536346d99d05f3694c5cf0d3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://chainer.org/
COMMENT=	Flexible framework of neural networks
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-protobuf>=2.6.1:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-filelock>=2.0.6:../../wip/py-filelock

USE_LANGUAGES=	c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
