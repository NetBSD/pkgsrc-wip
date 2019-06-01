# $NetBSD$

DISTNAME=		go-mux-${GITHUB_TAG}
PKGREVISION=		1
PKGNAME=		go-mux-1.7.2
GITHUB_PROJECT=		mux
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=gorilla/}
GITHUB_TAG=		ed099d42384823742bba0bf9a72b53b55c9e2e38

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/gorilla/go-mux
COMMENT=		URL router and dispatcher for Go
LICENSE=		modified-bsd # bsd-3

GO_SRCPATH=		github.com/gorilla/mux
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
