# $NetBSD: Makefile,v 1.4 2012/09/28 21:24:36 asau Exp $

DISTNAME=	discident-glib-0.9.9
CATEGORIES=	www
#MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/discident-glib/0.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://git.gnome.org/browse/discident-glib/
COMMENT=	Discident-glib is a convenience library for the DiscIdent Web Service
LICENSE=	gnu-gpl-v2

DEPENDS+=	gobject-introspection>=0.6.10:../../devel/gobject-introspection

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	discident-glib.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
