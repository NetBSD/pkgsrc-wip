# $NetBSD$

DISTNAME=	tuios-0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gaurav-Gosain/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gaurav-Gosain/tuios/
COMMENT=	Terminal UI Operating System (tiling window manager and multiplexer)
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

# Pure-Go backend only; the optional ghostty backend needs cgo + libghostty-vt.
GO_BUILD_PATTERN=	./cmd/tuios

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
