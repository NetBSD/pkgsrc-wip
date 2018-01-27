# $NetBSD: Makefile,v 1.2 2015/02/26 16:16:22 jgoamakf Exp $

DISTNAME=	variantslib-${VERS}
VERS=		109.15.03
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/variantslib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-variantslib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/variantslib/
COMMENT=	OCaml variants as first class values
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
