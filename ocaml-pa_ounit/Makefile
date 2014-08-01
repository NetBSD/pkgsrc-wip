# $NetBSD: Makefile,v 1.1 2014/08/01 01:51:14 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	pa_ounit-109.36.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/109.36.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_ounit/
COMMENT=	OCaml inline testing
LICENSE=	apache-2.0

DEPENDS+=	ocaml-ounit-[0-9]*:../../wip/ocaml-ounit

.include "../../wip/mk/ocaml-oasis.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
