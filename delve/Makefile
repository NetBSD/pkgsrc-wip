# $NetBSD$

DISTNAME=	delve-1.23.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-delve/}
CATEGORIES=	wip devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/go-delve/delve/
COMMENT=	Go debugger
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/dlv
GO_DIST_BASE=		${DISTNAME}

# needs upstream patches for OpenBSD, NetBSD, Illumos (and more?) support
ONLY_FOR_PLATFORM=	Linux-*-* Darwin-*-* FreeBSD-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/dlv ${DESTDIR}${PREFIX}/bin/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
