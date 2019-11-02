# $NetBSD: Makefile,v 1.20 2019/08/27 19:56:03 schmonz Exp $

GITHUB_PROJECT=	odoc
DISTNAME=	odoc-1.4.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/sedlex
COMMENT=	OCaml documentation generator
LICENSE=	isc

OCAML_USE_DUNE=	yes

.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../devel/ocaml-fpath/buildlink3.mk"
.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
