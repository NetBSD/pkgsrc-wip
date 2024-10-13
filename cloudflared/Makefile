# $NetBSD$

DISTNAME=	cloudflared-2024.10.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloudflare/}
GITHUB_PROJECT=	cloudflared

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/cloudflare/cloudflared/
COMMENT=	Cloudflare Tunnel client
LICENSE=	apache-2.0

.include "go-modules.mk"

GO_BUILD_DATE_cmd=	${DATE} -u '+%Y-%m-%d-%H%M UTC'
GO_BUILD_PATTERN+=	-ldflags ' \
			-X "main.Version=${PKGVERSION_NOREV}" \
			-X "main.BuildTime=${GO_BUILD_DATE_cmd:sh}"'
GO_BUILD_PATTERN+=	github.com/cloudflare/cloudflared/cmd/cloudflared

INSTALLATION_DIRS+=	bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
