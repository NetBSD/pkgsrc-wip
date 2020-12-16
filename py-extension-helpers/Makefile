# $NetBSD$

DISTNAME=	extension-helpers-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	extension-helpers
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kinoshita@astro.ncu.edu.tw
HOMEPAGE=	https://pypi.org/project/extension-helpers/
COMMENT=	helpers to assist with building Python packages
LICENSE=	modified-bsd

BUILD_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
