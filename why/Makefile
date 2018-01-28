# $NetBSD: Makefile,v 1.4 2015/07/10 09:50:01 thomasklausner Exp $

DISTNAME=	why-2.29
CATEGORIES=	devel
MASTER_SITES=	http://why.lri.fr/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://why.lri.fr/download/
COMMENT=	Why is a software verification platform

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
