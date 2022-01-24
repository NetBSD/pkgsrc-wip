# $NetBSD$

DISTNAME=	tree-sitter-0.20.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools
LICENSE=	mit

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	tree-sitter.pc.in

.include "../../mk/bsd.pkg.mk"
