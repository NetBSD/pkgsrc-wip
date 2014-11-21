# $NetBSD: Makefile,v 1.1 2014/11/21 06:24:55 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	yojson-1.1.8
CATEGORIES=	textproc
MASTER_SITES=	http://mjambon.com/releases/yojson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjambon.com/yojson.html
COMMENT=	JSON parsing and printing library for OCaml
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
BUILD_TARGET+=	all opt

OCAML_USE_FINDLIB=	yes

.include "../../wip/ocaml-biniou/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
