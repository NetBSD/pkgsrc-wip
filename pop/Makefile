# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	pop-6.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobuffalo/}

MAINTAINER=	rob@buglawton.com
HOMEPAGE=	https://github.com/gobuffalo/pop/
COMMENT=	Database migration tool
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c
USE_TOOLS=	gmake
NO_CHECKSUM=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
