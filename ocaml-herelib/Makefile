# $NetBSD: Makefile,v 1.4 2014/11/16 23:44:02 jgoamakf Exp $

DISTNAME=	herelib-${VERS}
VERS=		109.35.02
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/herelib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-herelib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/herelib/
COMMENT=	Syntax extension for inserting the current location
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
