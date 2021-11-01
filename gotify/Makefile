# $NetBSD$

GITHUB_GROUP=	gotify
GITHUB_PROJECT=	server
VERSION=	2.1.0
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_GROUP}-${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=${GITHUB_GROUP}/}

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gotify/server

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/gotify/server/
COMMENT=	Unified Push server
LICENSE=	mit

USE_LANGUAGES=	# none

# \todo Absorb and integrate:
# https://gotify.net/docs/build

.include "../..//lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
