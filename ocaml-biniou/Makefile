# $NetBSD: Makefile,v 1.2 2014/11/17 11:48:22 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	biniou-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://mjambon.com/releases/biniou/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjambon.com/biniou.html
COMMENT=	Extensible binary serialization format
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../wip/ocaml-easy-format/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
