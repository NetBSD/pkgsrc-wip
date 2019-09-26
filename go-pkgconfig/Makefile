# $NetBSD$

DISTNAME=		go-pkgconfig-${GITHUB_TAG}
PKGNAME=		go-pkgconfig-0.0.0
PKGREVISION=		1
GITHUB_PROJECT=		pkgconfig
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=xlab/}
GITHUB_TAG=		cea12a0fd2454f031cbce19aec911c1e92af25da

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/xlab/pkgconfig/
COMMENT=		Go clone of pkg-config(1)
LICENSE=		mit

GO_SRCPATH=		github.com/xlab/pkgconfig
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
