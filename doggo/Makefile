# $NetBSD$

DISTNAME=	doggo-1.1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mr-karan/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mr-karan/doggo/
COMMENT=	Connamd Line DNS client
LICENSE=	gpl3

# USE_TOOLS+=		gmake 

GO_BUILD_PATTERN=./cmd/doggo

.include "go-modules.mk"

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	go c

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
