# $NetBSD: Makefile,v 1.24 2021/01/23 14:22:52 bsiegert Exp $

DISTNAME=	dendrite-0.5.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	aaron@bolddaemon.com
HOMEPAGE=	https://github.com/matrix-org/dendrite
COMMENT=	Second-generation Matrix homeserver
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	github.com/matrix-org/dendrite/cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
