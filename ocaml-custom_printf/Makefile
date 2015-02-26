# $NetBSD: Makefile,v 1.1 2015/02/26 10:51:30 jgoamakf Exp $

DISTNAME=	custom_printf-${VERS}
VERS=		112.17.00
CATEGORIES=     devel
MASTER_SITES=   https://github.com/janestreet/custom_printf/archive/
DISTFILES=      ${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=    ocaml-custom_printf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/custom_printf/
COMMENT=	Syntax extension for printf format strings
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../wip/ocaml-pa_ounit/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
