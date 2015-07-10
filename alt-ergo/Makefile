# $NetBSD: Makefile,v 1.5 2015/07/10 12:37:44 thomasklausner Exp $

DISTNAME=	alt-ergo-0.93
CATEGORIES=	devel
MASTER_SITES=	-http://alt-ergo.ocamlpro.com/download_manager.php?target=${DISTNAME}${EXTRACT_SUFX}

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
