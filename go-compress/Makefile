# $NetBSD$

DISTNAME=		go-compress-${GITHUB_TAG}
PKGNAME=		go-compress-1.5.0
GITHUB_PROJECT=		compress
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=klauspost/}
GITHUB_TAG=		b4b6d9e7f099f14b3a4a08f0664986cd4c85ebd6

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/klauspost/compress/
COMMENT=		Optimized compression packages for Go
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/klauspost/compress
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../wip/go-cpuid/buildlink3.mk"
.include "../../wip/go-xxhash/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
