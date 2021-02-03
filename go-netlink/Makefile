# $NetBSD$

DISTNAME=	netlink-20210111
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	netlink
GITHUB_TAG=	8014f9a7dbf4fd7b84a1783dd7b470db9113ff36
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mdlayher/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mdlayher/netlink/
COMMENT=	Netlink provides low-level access to Linux netlink sockets
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/mdlayher/netlink

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-native/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
