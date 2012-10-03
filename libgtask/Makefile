# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=	gtask-0.1.2
PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.dronelabs.com/sources/gtask/0.1/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://chergert.github.com/gtask/
COMMENT=	Library for asynchronous and Callback-based execution for GObject
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	gtask.pc.in

.include "options.mk"

BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.14.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../wip/rss-glib/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
