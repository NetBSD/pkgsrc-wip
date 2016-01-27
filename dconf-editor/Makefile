# $NetBSD: Makefile,v 1.67 2015/12/05 21:26:08 adam Exp $

DISTNAME=		dconf-editor-3.16.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/dconf-editor/3.16/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2
LICENSE=		gnu-lgpl-v2.1

#BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

#CONFLICTS=		gnome-core-[0-9]* gnome2-terminal-[0-9]*

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES


BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.23.2
.include "../../wip/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.18.0
.include "../../lang/vala/buildlink3.mk"
#BUILDLINK_API_DEPENDS.gtk3+=	gtk3+=>3.4
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
