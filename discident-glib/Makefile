# $NetBSD: Makefile,v 1.3 2010/11/17 01:41:24 obache Exp $
#

DISTNAME=	discident-glib-0.9.9
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/discident-glib/0.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://git.gnome.org/browse/discident-glib/
COMMENT=	Discident-glib is a convenience library for the DiscIdent Web Service
LICENSE=	gnu-gpl-v2

DEPENDS+=	gobject-introspection>=0.6.10:../../devel/gobject-introspection

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	discident-glib.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
