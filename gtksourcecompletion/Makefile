# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	gtksourcecompletion-0.5.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtksourcecomple/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gtksourcecomple.sourceforge.net/
COMMENT=	GtkSourceCompletion
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt

PKGCONFIG_OVERRIDE+=	gtksourcecompletion-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
