# $NetBSD$

DISTNAME=		go-spew-${GITHUB_TAG}
PKGNAME=		go-spew-1.1.1
PKGREVISION=		1
GITHUB_PROJECT=		go-spew
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=davecgh/}
GITHUB_TAG=		8991bc29aa16c548c550c7ff78260e27b9ab7c73

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/davecgh/go-spew
COMMENT=		Deep pretty printer for Go data structures
LICENSE=		isc

GO_SRCPATH=		github.com/davecgh/go-spew
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
