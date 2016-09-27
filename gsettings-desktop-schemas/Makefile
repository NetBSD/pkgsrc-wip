# $NetBSD: Makefile,v 1.7 2016/04/22 23:11:01 prlw1 Exp $

GNOME3_MAJOR_VERSION=	22
GNOME3_MINOR_VERSION=	0

DISTNAME=	gsettings-desktop-schemas-3.${GNOME3_MAJOR_VERSION}.${GNOME3_MINOR_VERSION}
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gsettings-desktop-schemas/3.${GNOME3_MAJOR_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Collection of GSettings schemas for the GNOME desktop
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
# Necessary because of configure test
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	gsettings-desktop-schemas.pc.in

.include "../../devel/glib2/schemas.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.31
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
