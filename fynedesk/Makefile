# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	fynedesk-0.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fyne-io/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://fyne.io/fynedesk/
COMMENT=	Desktop environment based on Fyne toolkit
LICENSE=	modified-bsd

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
