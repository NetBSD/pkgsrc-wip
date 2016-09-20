# $NetBSD: Makefile,v 1.5 2015/07/10 12:37:44 thomasklausner Exp $

GITHUB_PROJECT=	alt-ergo
GITHUB_TAG=	4a61506e48300b386fee5b2e09a28a045beb4491
DISTNAME=	alt-ergo-1.01
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCamlPro/}

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://ergo.lri.fr/
COMMENT=	Automatic theorem prover for program verification

USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c


.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
