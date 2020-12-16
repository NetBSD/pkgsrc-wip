# $NetBSD$

DISTNAME=	pyerfa-1.7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=liberfa/}
GITHUB_PROJECT=	pyerfa
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kinoshita@astro.ncu.edu.tw
HOMEPAGE=	https://github.com/liberfa/pyerfa/
COMMENT=	Python wrapper for ERFA library
LICENSE=	modified-bsd

MAKE_ENV+=	PYERFA_USE_SYSTEM_LIBERFA=1

USE_LIBTOOL=	yes
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	git>=2:../../devel/git
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	erfa>=1.7.1:../../wip/erfa

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init; \
	cd liberfa; \
	git config --global http.sslVerify false; \
	git clone https://github.com/liberfa/erfa.git;

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/erfa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
