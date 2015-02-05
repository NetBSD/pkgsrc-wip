# $NetBSD: Makefile,v 1.1 2015/02/05 01:39:41 jgoamakf Exp $

DISTNAME=	pa_test-${VERS}
VERS=		111.08.00
CATEGORIES=	devel
MASTER_SITES=   https://github.com/janestreet/pa_test/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-pa_test

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_test/
COMMENT=	Quotation expanders for assertions
LICENSE=	apache-2.0

OCAML_USE_OASIS=yes

.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
