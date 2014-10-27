# $NetBSD: Makefile,v 1.2 2014/10/27 08:20:58 jgoamakf Exp $

DISTNAME=	sexplib-${VERS}
VERS=		112.01.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/sexplib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-sexplib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

WRKSRC=		${WRKDIR}/sexplib-${VERS}
USE_TOOLS+=	gmake

#OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
