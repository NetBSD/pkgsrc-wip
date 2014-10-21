# $NetBSD: Makefile,v 1.2 2014/10/21 06:29:08 jgoamakf Exp $

DISTNAME=	herelib-${VERS}
VERS=		109.35.02
CATEGORIES=     devel
MASTER_SITES=   https://github.com/janestreet/herelib/archive/
DISTFILES=      ${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=    ocaml-herelib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/herelib/
COMMENT=	Syntax extension for inserting the current location
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/herelib-${VERS}
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
