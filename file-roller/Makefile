# $NetBSD: Makefile,v 1.137 2016/08/03 10:22:26 adam Exp $

GNOME3_MAJOR_VERSION=	22
GNOME3_MINOR_VERSION=	0
DISTNAME=		file-roller-3.${GNOME3_MAJOR_VERSION}.${GNOME3_MINOR_VERSION}
CATEGORIES=		archivers gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/file-roller/3.${GNOME3_MAJOR_VERSION}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gtar:run intltool msgfmt perl pkg-config unzip:run
USE_TOOLS+=		zip:run
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		FileRoller.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0

# Force unzip from pkgsrc on NetBSD
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
#.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
