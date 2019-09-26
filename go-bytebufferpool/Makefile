# $NetBSD$
#

DISTNAME=		go-bytebufferpool-${GITHUB_TAG}
PKGNAME=		go-bytebufferpool-1.0.0
PKGREVISION=		1
GITHUB_PROJECT=		bytebufferpool
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=valyala/}
GITHUB_TAG=		e746df99fe4a3986f4d4f79e13c1e0117ce9c2f7

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/valyala/bytebufferpool/
COMMENT=		Implementation of a pool of byte buffers with anti-memory-waste protection for Go
LICENSE=		mit

GO_SRCPATH=		github.com/valyala/bytebufferpool
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
