# $NetBSD: Makefile,v 1.2 2014/10/21 02:40:29 jgoamakf Exp $

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

WRKSRC=		${WRKDIR}/comparelib-${VERS}
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
