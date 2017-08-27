# $NetBSD$

# XXX 0.0.1 is a made-up release number, watch for a release:
# https://github.com/dustin/go-humanize/issues/56
PKGNAME=	go-humanize-0.0.1
GITHUB_TAG=	383332499bf02f79d3e696220c2713722438529c
DISTNAME=	go-humanize-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dustin/}
GITHUB_PROJECT=	go-humanize

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/dustin/go-humanize
COMMENT=	Go Humans! (formatters for units to human friendly sizes)
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	go-humanize-${GITHUB_TAG}
GO_SRCPATH=	github.com/dustin/go-humanize

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
