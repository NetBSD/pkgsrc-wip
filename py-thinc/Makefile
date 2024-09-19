# $NetBSD$


DISTNAME=	thinc-v8.0.2
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
GITHUB_PROJECT=	thinc

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/thinc/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV:S/v//1}

# url2pkg-marker (please do not remove this line.)
.include	"../../lang/python/egg.mk"
.include	"../../math/py-numpy/buildlink3.mk"
.include	"../../wip/py-cymem/buildlink3.mk"
.include	"../../wip/py-preshed/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
