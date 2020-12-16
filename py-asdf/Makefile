# $NetBSD$

DISTNAME=	asdf-2.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=asdf-format/}
GITHUB_PROJECT=	asdf
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kinoshita@astro.ncu.edu.tw
HOMEPAGE=	https://github.com/asdf-format/
COMMENT=	Advanced Scientific Data Format
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36
REPLACE_PYTHON=			asdf-standard/reference_files/generate/generate

BUILD_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.10.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.2:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-lz4>=0.10:../../archivers/py-lz4

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init; \
	git config --global http.sslVerify false; \
	git clone https://github.com/spacetelescope/asdf-standard.git;

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
