# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-v0.7.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
GITHUB_PROJECT=	cython-blis

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/cython-blis/
COMMENT=	Blis linear algebra routines as a self-contained Python C-extension
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV:S/v//1}

# url2pkg-marker (please do not remove this line.)
.include	"../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
