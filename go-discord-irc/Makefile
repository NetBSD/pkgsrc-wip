# $NetBSD: Makefile,v 1.16 2021/01/27 13:35:58 leot Exp $

DISTNAME=	go-discord-irc-1.0.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=qaisjp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/qaisjp/go-discord-irc
COMMENT=	Discord and IRC bridge with puppets
LICENSE=	mit

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
