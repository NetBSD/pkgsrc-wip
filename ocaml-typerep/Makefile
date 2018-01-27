# $NetBSD: Makefile,v 1.2 2015/02/26 16:14:20 jgoamakf Exp $

DISTNAME=	typerep-${VERS}
VERS=		112.17.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/typerep/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-typerep

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/typerep/
COMMENT=	Runtime types for OCaml
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../wip/ocaml-bin_prot/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
