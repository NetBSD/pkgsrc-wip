# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:07 asau Exp $
#

DISTNAME=	why-2.29
CATEGORIES=	devel
MASTER_SITES=	http://why.lri.fr/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://why.lri.fr/download/
COMMENT=	Why is a software verification platform

GNU_CONFIGURE=	yes

USE_TOOLS+= 	gmake

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ocamlgraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
