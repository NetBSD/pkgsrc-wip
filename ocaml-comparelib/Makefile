# $NetBSD: Makefile,v 1.1 2014/06/12 07:58:58 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	comparelib-109.60.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/109.60.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/comparelib/
COMMENT=	Syntax extension for deriving "compare" functions automatically
LICENSE=	apache-2.0

DEPENDS+=	ocaml-type_conv-[0-9]*:../../wip/ocaml-type_conv

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../wip/mk/ocaml-oasis.mk"
.include "../../mk/bsd.pkg.mk"
