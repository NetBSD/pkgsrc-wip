# $NetBSD$

DISTNAME=	zf-0.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=natecraddock/}
GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	zf

GITHUB_SUBMODULES+=	jecolon ziglyph 8d347309cef3c9ad210ff001f43f1b332d5e615f lib/ziglyph

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/natecraddock/zf/
COMMENT=	Commandline fuzzy finder designed for filtering filepaths
LICENSE=	mit

# \todo: There is currently an issue building this as RELRO.
RELRO_SUPPORTED=	no

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
