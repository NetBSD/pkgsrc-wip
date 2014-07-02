# $NetBSD: Makefile,v 1.1 2014/07/02 05:06:57 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	biniou-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://mjambon.com/releases/biniou/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjambon.com/biniou.html
COMMENT=	Extensible binary serialization format
LICENSE=	modified-bsd

DEPENDS+=	ocaml-easy-format-[0-9]*:../../wip/ocaml-easy-format

USE_TOOLS+=	gmake

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
