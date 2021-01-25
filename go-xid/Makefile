# $NetBSD$

DISTNAME=	xid-20201019
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	xid
GITHUB_TAG=	efa678f304ab65d6d57eedcb086798381ae22206
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rs/xid/
COMMENT=	Globally unique id generator thought for the web
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/rs/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
