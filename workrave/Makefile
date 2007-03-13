# $NetBSD: Makefile,v 1.1.1.1 2007/03/13 18:58:35 briandealwis Exp $
#

PKGNAME=		workrave-1.8.4
DISTNAME=		${PKGNAME}-2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=workrave/}

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://www.workrave.org/
COMMENT=		Wrist break reminder program for prevention of RSI

USE_LIBTOOL=            YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=             gmake pkg-config intltool
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR:Q}

# Under NetBSD, /usr/include/wchar.h requires either _ISOC99_SOURCE or
# _NETBSD_SOURCE to be defined to include definitions for vfwscanf, vswscanf,
# vwscanf, and wcstof (required by backend/src/Break.cc), since
# __STDC_VERSION__ doesn't appear to be defined by c++
CXXFLAGS+=		-D_ISOC99_SOURCE

# XXX These should be moved into an options.mk framework
CONFIGURE_ARGS+=	--with-x \
			--disable-gnome --disable-gnomemm --disable-kde
# --disable-app-gtk --disable-gconf
# --without-arts
# --enable-dbus
# --enable-gnome
# --enable-gnomemm
# --enable-kde

# XXX for KDE, need to set kdesoundsdir?
INSTALL_MAKE_FLAGS+=	utilsdir=${EGDIR}/sound/events
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/sound/events/workrave.soundlist \
    		${PKG_SYSCONFDIR}/sound/events/workrave.soundlist

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gdome2/buildlink3.mk"

# GTK support
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"

# GConf support
.include "../../devel/GConf2/buildlink3.mk"

# GNOME support
#.include "../../devel/libgnomeui/buildlink3.mk"
#.include "../../x11/gnome-panel/buildlink3.mk"
#.include "../../devel/libbonobo/buildlink3.mk"
#.include "../../net/ORBit2/buildlink3.mk"

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
