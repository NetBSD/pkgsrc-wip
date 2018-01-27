# $NetBSD: Makefile,v 1.3 2014/11/21 06:01:35 jgoamakf Exp $

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
BUILD_TARGET+=		opt

.include "../../wip/ocaml-easy-format/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
