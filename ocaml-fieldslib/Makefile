# $NetBSD: Makefile,v 1.1 2014/06/10 06:10:25 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	fieldslib-109.19.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/109.19.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/fieldslib/
COMMENT=	Define first class values representing record fields
LICENSE=	apache-2.0

DEPENDS+=	ocaml-type_conv-[0-9]*:../../wip/ocaml-type_conv

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../wip/mk/ocaml-oasis.mk"
.include "../../mk/bsd.pkg.mk"
