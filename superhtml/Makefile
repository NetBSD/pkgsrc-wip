# $NetBSD$

DISTNAME=	superhtml-0.5.0
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristoff-it/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kristoff-it/superhtml/
COMMENT=	HTML Language Server (LSP)
LICENSE=	mit

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=	yes

PKGCONFIG_OVERRIDE+=	tree-sitter-superhtml/bindings/c/tree-sitter-html.pc.in

ZIGPIE=			no
MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
