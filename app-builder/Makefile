# $NetBSD: Makefile,v 1.5 2026/11/10 18:55:10 bsiegert Exp $

DISTNAME=	app-builder-4.2.0
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=develar/}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://github.com/develar/app-builder
COMMENT=	Generic helper tool to build app in a distributable format
LICENSE=	mit

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
