# $NetBSD$

GITHUB_PROJECT=	delve
GITHUB_TAG=	v0.12.1
DISTNAME=	delve-0.12.1
CATEGORIES=	wip devel
MASTER_SITES=	https://github.com/derekparker/
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=derekparker/delve/}
COMMENT=	Go debugger
LICENSE=	mit

GO_SRCPATH=		github.com/derekparker/delve
GO_BUILD_PATTERN=	${GO_SRCPATH}/cmd/dlv
GO_DIST_BASE=		${DISTNAME}

# needs patches for BSD support
ONLY_FOR_PLATFORM=	Linux-*-* Darwin-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/dlv ${DESTDIR}${PREFIX}/bin/

.include "../../lang/go/go-package.mk"
.include "../../mk/fetch/github.mk"
.include "../../mk/bsd.pkg.mk"
