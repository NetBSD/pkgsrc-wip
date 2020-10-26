# $NetBSD$

DISTNAME=	pandera-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandera/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pandera-dev/pandera
COMMENT=	Flexible validation package for pandas data structures
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-autopep8>=1.5.4:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.12.1:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-black>=2.8:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-inspect>=0.6.0:../../wip/py-typing-inspect
.endif


USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.9.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
