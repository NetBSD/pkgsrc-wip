# $NetBSD$

GITHUB_PROJECT=	bumpversion
GITHUB_TAG=	v0.5.3
DISTNAME=	v0.5.3
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=peritus/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/peritus/bumpversion
COMMENT=	Version-bump your software with a single command!
LICENSE=	mit

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
