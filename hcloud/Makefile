# $NetBSD$

DISTNAME=	hcloud-1.49.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hetznercloud/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	cli

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hetznercloud/cli
COMMENT=	Command-line interface for Hetzner Cloud
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/hetznercloud/cli/internal/version.Version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/hcloud

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
