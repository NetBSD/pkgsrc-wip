# $NetBSD$

DISTNAME=	Keras-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keras/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/fchollet/keras
COMMENT=	Deep Learning for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pyaml>=17.10.0:../../textproc/py-pyaml
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.7.1:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-Keras_Applications>=1.0.6:../../wip/py-Keras_Applications
DEPENDS+=	${PYPKGPREFIX}-Keras_Preprocessing>=1.0.5:../../wip/py-Keras_Preprocessing

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
