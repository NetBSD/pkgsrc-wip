# $NetBSD$

DISTNAME=	uunf-16.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbuenzli/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/dbuenzli/uunf/
COMMENT=	OCaml library for normalizing Unicode text
LICENSE=	isc

# Consider hoisting this to github.mk?
WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=

.include "../../lang/ocaml/ocaml.mk"
OCAML_USE_DUNE=	yes
OCAML_USE_OPAM=	yes

do-build:
	cd ${WRKSRC} && ocaml pkg/pkg.ml build

# Earliier, it seemed to demand uutf, despite documenting no dependencies.
#.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
