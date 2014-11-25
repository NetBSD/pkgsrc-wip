# $NetBSD: Makefile,v 1.3 2014/11/25 09:35:06 jgoamakf Exp $

DISTNAME=	pa_ounit-${VERS}
VERS=		111.28.00
CATEGORIES=     devel
MASTER_SITES=   https://github.com/janestreet/pa_ounit/archive/
DISTFILES=      ${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=    ocaml-pa_ounit

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_ounit/
COMMENT=	OCaml inline testing
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../wip/ocaml-ounit/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
