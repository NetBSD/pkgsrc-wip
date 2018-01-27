# $NetBSD: Makefile,v 1.4 2015/02/26 15:59:56 jgoamakf Exp $

DISTNAME=	fieldslib-${VERS}
VERS=		109.20.03
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/fieldslib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-fieldslib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/fieldslib/
COMMENT=	Define first class values representing record fields
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
