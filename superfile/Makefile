# $NetBSD$

DISTNAME=	superfile-1.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=MHNightCat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MHNightCat/superfile/
COMMENT=	Pretty fancy and modern terminal file manager
LICENSE=	mit

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
