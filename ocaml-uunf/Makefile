# $NetBSD$

DISTNAME=	uunf-16.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbuenzli/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/dbuenzli/uunf/
COMMENT=	OCaml library for normalizing Unicode text
LICENSE=	isc

TOOL_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
TOOL_DEPENDS+=	ocamlbuild-[0-9]*:../../devel/ocamlbuild
TOOL_DEPENDS+=	ocaml-topkg-[0-9]*:../../misc/ocaml-topkg

# Consider hoisting this to github.mk?
WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=

.include "../../lang/ocaml/ocaml.mk"
OCAML_USE_DUNE=			yes
OCAML_USE_OPAM=			yes
# Compiler crashes during build.
OCAML_USE_OPT_COMPILER=		no

do-build:
	cd ${WRKSRC} && ocaml pkg/pkg.ml build

# Earliier, it seemed to demand uutf, despite documenting no dependencies.
#.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
