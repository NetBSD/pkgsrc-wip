# $NetBSD$

GITHUB_PROJECT=	dpkt
GITHUB_TAG=	v1.9.4
DISTNAME=	v1.9.4
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kbandla/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/kbandla/dpkt
COMMENT=	Python packet creation / parsing library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
