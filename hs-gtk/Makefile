# $NetBSD: Makefile,v 1.4 2014/05/16 20:47:10 szptvlfn Exp $
#

DISTNAME=	gtk-0.12.3
CATEGORIES=	x11

MAINTAINER=	pho@cielonegro.org
COMMENT=	Binding to the Gtk+ graphical user interface library
LICENSE=	gnu-lgpl-v2.1

.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/gtk2hs-buildtools/buildlink3.mk"
.include "../../wip/hs-cairo/buildlink3.mk"
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
