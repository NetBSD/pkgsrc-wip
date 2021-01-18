# $NetBSD$

DISTNAME=	go-ping-20201115
GITHUB_PROJECT=	ping
GITHUB_TAG=	3300c582a663c5bce1d0ecf1868107da0ae38829
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-ping/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/go-ping/ping
COMMENT=	ICMP Ping library for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/go-ping/ping

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
