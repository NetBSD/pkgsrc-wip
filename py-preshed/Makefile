# $NetBSD$


DISTNAME=	preshed-v2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/v//1}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
GITHUB_PROJECT=	preshed

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/preshed/
COMMENT=	Cython hash table mapping
LICENSE=	mit


WRKSRC=		${WRKDIR}/${DISTNAME:S/v//1}
USE_LANGUAGES=	c c++


#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
