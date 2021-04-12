# $NetBSD$

DISTNAME=	murmurhash-v1.0.1
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/murmurhash/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV:S/v//1}
USE_LANGUAGES= c c++


# url2pkg-marker (please do not remove this line.)
.include	"../../lang/python/egg.mk"
.include	"../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
