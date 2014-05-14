# $NetBSD: Makefile,v 1.1 2014/05/14 07:23:03 jgoamakf Exp $

DISTNAME=	ocaml-data-notation-0.0.11
CATEGORIES=	devel
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/1310/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.ocamlcore.org/projects/odn/
COMMENT=	Dump OCaml data structures using OCaml data notation
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	ocaml-type_conv-[0-9]*:../../wip/ocaml-type_conv

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../wip/mk/ocaml-oasis.mk"
.include "../../mk/bsd.pkg.mk"
