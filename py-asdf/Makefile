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

DEPENDS+=	git>=2:../../devel/git

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init; \
	git config --global http.sslVerify false; \
	git clone https://github.com/spacetelescope/asdf-standard.git;

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
