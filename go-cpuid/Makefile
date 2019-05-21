# $NetBSD$

DISTNAME=		go-cpuid-${GITHUB_TAG}
PKGNAME=		go-cpuid-1.2.1
GITHUB_PROJECT=		cpuid
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=klauspost/}
GITHUB_TAG=		05a8198c0f5a27739aec358908d7e12c64ce6eb7

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/klauspost/cpuid/
COMMENT=		CPU feature identification for Go
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/klauspost/cpuid
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
