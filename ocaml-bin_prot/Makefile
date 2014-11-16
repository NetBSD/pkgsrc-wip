# $NetBSD: Makefile,v 1.5 2014/11/16 23:12:34 jgoamakf Exp $

DISTNAME=	bin_prot-${VERS}
VERS=		112.01.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/bin_prot/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-bin_prot

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/bin_prot/
COMMENT=	Read and write OCaml-values in a type-safe binary protocol
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
