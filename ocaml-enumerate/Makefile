# $NetBSD: Makefile,v 1.1 2014/07/11 00:49:00 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	enumerate-111.08.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/111.08.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	Quotation expanders for enumerating finite types
LICENSE=	apache-2.0

DEPENDS+=	ocaml-type_conv-[0-9]*:../../wip/ocaml-type_conv

.include "../../wip/mk/ocaml-oasis.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
