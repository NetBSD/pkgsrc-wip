# $NetBSD: Makefile,v 1.2 2012/03/11 08:17:52 phonohawk Exp $
#

DISTNAME=	gtk-0.12.3
CATEGORIES=	x11

MAINTAINER=	pho@cielonegro.org
COMMENT=	Binding to the Gtk+ graphical user interface library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/gtk2hs-buildtools/buildlink3.mk"
.include "../../wip/hs-cairo/buildlink3.mk"
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
