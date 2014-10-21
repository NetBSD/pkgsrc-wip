# $NetBSD: Makefile,v 1.2 2014/10/21 02:36:49 jgoamakf Exp $

DISTNAME=	enumerate-${VERS}
VERS=		111.08.00
CATEGORIES=     devel
MASTER_SITES=   https://github.com/janestreet/enumerate/archive/
DISTFILES=      ${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=    ocaml-enumerate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/enumerate/
COMMENT=	Quotation expanders for enumerating finite types
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/enumerate-${VERS}
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
