# $NetBSD: Makefile,v 1.4 2025/06/06 14:01:33 bsiegert Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.88.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	8acbb2407e3f8df596e13ac3f124c4c89f08100a

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://tailscale.com/
COMMENT=	Wireguard-based VPN client for tailscale
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscale
GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscaled

RCD_SCRIPTS+=	tailscaled

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
