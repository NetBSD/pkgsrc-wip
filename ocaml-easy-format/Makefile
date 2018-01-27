# $NetBSD: Makefile,v 1.3 2014/11/21 05:51:07 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	easy-format-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://mjambon.com/releases/easy-format/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjambon.com/easy-format.html
COMMENT=	High-level and functional interface to the OCaml Format module
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes
BUILD_TARGET+=		opt

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
