# $NetBSD$

GITHUB_PROJECT=	ocaml-cairo
DISTNAME=	${GITHUB_PROJECT}-0.6.1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/Chris00/ocaml-cairo/
COMMENT=	Bindings for OCaml to the cairo library
#LICENSE=	# TODO: (see mk/license.mk)

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	cairo2
OPAM_INSTALL_FILES=	cairo2

.include "../../mk/ocaml.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
