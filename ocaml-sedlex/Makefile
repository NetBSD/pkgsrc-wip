# $NetBSD: Makefile,v 1.20 2019/08/27 19:56:03 schmonz Exp $

DISTNAME=	ocaml-sedlex-2.1
GITHUB_PROJECT=	sedlex
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	netbsd-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/sedlex
COMMENT=	OCaml lexer generator for Unicode
LICENSE=	mit

USE_TOOLS+=	gmake

OCAML_USE_DUNE=	yes
BUILD_DEPENDS+=	ocaml-odoc-[0-9]*:../../wip/ocaml-odoc

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../wip/ocaml-gen/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
