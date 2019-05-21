# $NetBSD$

DISTNAME=		go-tcplisten-${GITHUB_TAG}
PKGNAME=		go-tcplisten-0.0.0
GITHUB_PROJECT=		tcplisten
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=valyala/}
GITHUB_TAG=		ceec8f93295a060cdb565ec25e4ccf17941dbd55

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/valyala/tcplisten/
COMMENT=		Customizable TCP net.Listener for Go
LICENSE=		mit

GO_SRCPATH=		github.com/valyala/tcplisten
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
