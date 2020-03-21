# $NetBSD: Makefile,v 1.14 2018/03/04 15:52:20 bsiegert Exp $

DISTNAME=		vgo-20180220
PKGREVISION=		12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		vgo
GITHUB_TAG=		085872f6d9

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://godoc.org/golang.org/x/vgo
COMMENT=		Versioned Go prototype
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/vgo
GO_BUILD_PATTERN=	${GO_SRCPATH}
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

CHECK_RELRO_SKIP+=	bin/vgo

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/vgo ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
