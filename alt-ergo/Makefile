# $NetBSD: Makefile,v 1.1 2011/05/21 19:14:41 marko_schuetz Exp $
#

DISTNAME=	alt-ergo-0.93
CATEGORIES=	devel
MASTER_SITES=	http://ergo.lri.fr/http/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://ergo.lri.fr/http/
COMMENT=	Automatic theorem prover for program verification

USE_TOOLS+=	gmake
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c


.include "../../lang/ocaml/buildlink3.mk"
.include "../../wip/ocamlgraph/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
