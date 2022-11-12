# $NetBSD: Makefile,v 1.3 2014/11/16 23:17:31 jgoamakf Exp $

DISTNAME=	comparelib-${VERS}
VERS=		109.60.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/comparelib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-comparelib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/comparelib/
COMMENT=	Syntax extension for deriving "compare" functions automatically
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
