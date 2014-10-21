# $NetBSD: Makefile,v 1.2 2014/10/21 06:28:09 jgoamakf Exp $

DISTNAME=	fieldslib-${VERS}
VERS=		109.19.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/fieldslib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-fieldslib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/fieldslib/
COMMENT=	Define first class values representing record fields
LICENSE=	apache-2.0

WRKSRC=         ${WRKDIR}/fieldslib-${VERS}
USE_TOOLS+=     gmake

OCAML_USE_OASIS=      yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
