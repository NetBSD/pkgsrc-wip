# $NetBSD: Makefile,v 1.4 2014/11/17 01:19:48 jgoamakf Exp $

DISTNAME=	enumerate-${VERS}
VERS=		111.08.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/enumerate/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-enumerate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/enumerate/
COMMENT=	Quotation expanders for enumerating finite types
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
