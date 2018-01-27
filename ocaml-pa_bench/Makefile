# $NetBSD: Makefile,v 1.2 2015/02/26 16:02:45 jgoamakf Exp $

DISTNAME=	pa_bench-${VERS}
VERS=		112.06.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/pa_bench/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-pa_bench

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_bench/
COMMENT=	Syntax extension for inline benchmarks
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../wip/ocaml-pa_ounit/buildlink3.mk"
.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
