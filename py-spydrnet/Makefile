# $NetBSD$

GITHUB_PROJECT=	spydrnet
DISTNAME=	spydrnet-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=byuccl/}
GITHUB_RELEASE=	v1.13.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://byuccl.github.io/spydrnet
COMMENT=	Python package for analyzing and transforming netlists
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
