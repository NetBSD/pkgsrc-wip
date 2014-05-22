# $NetBSD: Makefile,v 1.1 2014/05/22 08:45:46 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	easy-format-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://mjambon.com/releases/easy-format/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjambon.com/easy-format.html
COMMENT=	High-level and functional interface to the OCaml Format module
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
