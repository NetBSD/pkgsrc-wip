# $NetBSD: Makefile,v 1.3 2012/11/13 22:25:29 othyro Exp $

DISTNAME=	aravis-0.1.0
CATEGORIES=	graphics multimedia
#MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/aravis/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://live.gnome.org/Aravis
COMMENT=	Vision library for genicam based cameras
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool gmake pkg-config

PKGCONFIG_OVERRIDE+=	aravis.pc.in

.include "options.mk"

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
