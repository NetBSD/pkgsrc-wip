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

do-build:
	cd ${WRKSRC} && ocaml pkg/pkg.ml build

# Why does ocaml-topkg have a bl3 if it's a build tool?
#.include "../../misc/ocaml-topkg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
