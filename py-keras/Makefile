# $NetBSD$

DISTNAME=	Keras-2.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keras/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/fchollet/keras
COMMENT=	Deep Learning for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pyaml>=17.10.0:../../textproc/py-pyaml
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.7.1:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-test>=3.3.1:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-dot>=1.2.0:../../graphics/py-dot
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.21.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.20.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
