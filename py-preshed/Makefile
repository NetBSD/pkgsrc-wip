# $NetBSD$


DISTNAME=	preshed-v2.0.0
PKGNAME=	${DISTNAME:S/v//1}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
GITHUB_PROJECT=	preshed

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/preshed/
COMMENT=	Short description of the package
LICENSE=	mit


WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++


#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
