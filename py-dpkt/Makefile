# $NetBSD$

DISTNAME=	dpkt-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kbandla/}
GITHUB_PROJECT=	dpkt
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/kbandla/dpkt
COMMENT=	Python packet creation / parsing library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
