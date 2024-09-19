# $NetBSD$

DISTNAME=	madonctl-${GITHUB_TAG}
PKGNAME=	madonctl-2.3.1.1
CATEGORIES=	net chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=McKael/}
GITHUB_TAG=	8d3e9fa1028569dd4d6dbdfbe777c39f5b721650

HOMEPAGE=	https://lilotux.net/~mikael/pub/madonctl/
COMMENT=	Command line client for the Mastodon distributed social network API
LICENSE=	mit

EXTRACT_USING=		bsdtar
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
