# $NetBSD: Makefile,v 1.5 2009/12/05 08:34:10 obache Exp $
#

DISTNAME=	ibus-1.2.0.20091204
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Intelligent Input Bus
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=		ibus.schemas
PKGCONFIG_OVERRIDE+=	ibus-1.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

BUILD_DEFS+=	PKG_SYSCONFBASE

EXAMPLESDIR=		${PREFIX}/share/examples/ibus

INSTALL_MAKE_FLAGS+=	sysconfdir=${EXAMPLESDIR}

CONF_FILES+=		${EXAMPLESDIR}/xdg/autostart/ibus.desktop \
			${PKG_SYSCONFBASE}/xdg/autostart/ibus.desktop

SUBST_CLASSES+=		iso
SUBST_STAGE.iso=	post-configure
SUBST_FILES.iso=	ibus/lang.py
SUBST_SED.iso=		-e "s;/usr/share;${BUILDLINK_PREFIX.iso-codes}/share;"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=		${PYPKGPREFIX}-dbus>=0.83.0
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
