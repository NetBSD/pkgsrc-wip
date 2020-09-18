# $NetBSD$

GITHUB_PROJECT=	wasm
GITHUB_TAG=	v1.2
DISTNAME=	v1.2
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=athre0z/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/athre0z/wasm
COMMENT=	WebAssembly decoder & disassembler
LICENSE=	mit

DEPENDS+=	py-setuptools>=0:../../devel/py-setuptools

WRKSRC=		${WRKDIR}/wasm-1.2
USE_LANGUAGES=	c++

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
