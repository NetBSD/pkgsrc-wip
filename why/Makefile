# $NetBSD: Makefile,v 1.1 2011/05/21 18:27:39 marko_schuetz Exp $
#

DISTNAME=	why-2.29
CATEGORIES=	devel
MASTER_SITES=	http://why.lri.fr/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://why.lri.fr/download/
COMMENT=	Why is a software verification platform

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= 	gmake

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ocamlgraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
