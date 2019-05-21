# $NetBSD$

DISTNAME=		go-xxhash-${GITHUB_TAG}
PKGNAME=		go-xxhash-2.0.0
GITHUB_PROJECT=		xxhash
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=cespare/}
GITHUB_TAG=		3b82fb7d186719faeedd0c2864f868c74fbf79a1

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/cespare/xxhash/
COMMENT=		Go implementation of the 64bit xxhash algorithm XXh64
LICENSE=		mit

GO_SRCPATH=		github.com/cespare/xxhash
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
