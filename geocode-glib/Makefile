# $NetBSD: Makefile,v 1.67 2015/12/05 21:26:08 adam Exp $

DISTNAME=		geocode-glib-3.18.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/geocode-glib/3.18/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Geocoding library
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

BUILDLINK_API_DEPENDS.json-glib=	json-glib>=0.99.2
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=		libxml2>=2.6.
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=		libsoup>=2.34.0
.include "../../net/libsoup/buildlink3.mk"
BUILDLINK_API_DEPENDS.GConf+=		GConf>=2.31.3
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.35.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk3+=		gtk3+>=3.13.5
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
