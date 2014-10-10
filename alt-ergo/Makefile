# $NetBSD: Makefile,v 1.3 2014/10/10 14:03:21 thomasklausner Exp $
#

DISTNAME=	alt-ergo-0.93
CATEGORIES=	devel
MASTER_SITES=	http://ergo.lri.fr/http/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://ergo.lri.fr/http/
COMMENT=	Automatic theorem prover for program verification

USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c


.include "../../lang/ocaml/buildlink3.mk"
.include "../../wip/ocamlgraph/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
