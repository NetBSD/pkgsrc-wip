# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:07 thomasklausner Exp $
#

DISTNAME=	gtksourcecompletion-0.5.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtksourcecomple/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gtksourcecomple.sourceforge.net/
COMMENT=	GtkSourceCompletion
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT= user-destdir
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR= yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt

PKGCONFIG_OVERRIDE+=	gtksourcecompletion-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
