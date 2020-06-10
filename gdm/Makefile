# $NetBSD: Makefile,v 1.6 2015/06/06 20:44:44 krytarowski Exp $

DISTNAME=	gdm-3.36.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Gnome Display Manager

DEPENDS+=	zenity>=2.16.0:../../wip/zenity

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_TOOLS+=		automake autoconf autoreconf
BUILD_DEFS+=		VARBASE

USE_LANGUAGES=		c c++

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-dmconfdir=${PKG_SYSCONFDIR}/dm
CONFIGURE_ARGS+=	--with-sysconfsubdir=
CONFIGURE_ARGS+=	--with-prefetch=yes
CONFIGURE_ARGS+=	--without-plymouth
CONFIGURE_ARGS+=	--without-systemd
CONFIGURE_ARGS+=	--disable-systemd-journal
CONFIGURE_ARGS+=	--disable-user-display-server
CONFIGURE_ARGS+=	--with-user=${GDMOWN}
CONFIGURE_ARGS+=	--with-group=${GDMGRP}
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_SCRIPT=	./autogen.sh
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	GDM_CUSTOM_CONF=${EGDIR}/custom.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostLogin
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/dm
OWN_DIRS+=		${PKG_SYSCONFDIR}/modules
OWN_DIRS+=		${VARBASE}/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

PKG_SYSCONFSUBDIR=	gdm
EGDIR=			${PREFIX}/share/examples/gdm
CONF_FILES=		${EGDIR}/custom.conf ${PKG_SYSCONFDIR}/custom.conf

RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

# The following forces the X server to start on the 5th virtual terminal.
# This is suboptimal but matches the defaults for the xdm configuration,
# which should work for most installations.  See the definition of
# DEFAULTVT in xsrc/xfree/xc/programs/xdm/config/Imakefile.
#
# If we do not do this, we hit a very annoying and obscure problem: during
# system startup, gdm starts before init spawns gettys.  If the X server
# is started before init spawns the gettys (which easily happens on slow
# machines), it grabs the first virtual terminal (instead of the first
# "free" one).  Later on, when the first getty is started, it grabs the
# same terminal X used (the first one).  As a result, only one of them
# will receive key presses.  And on slow machines, X will have lost access
# to the keyboard.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD") && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

PLIST_VARS+=		dmx
.if exists(${X11BASE}/include/X11/extensions/dmxext.h)
PLIST.dmx=		yes
.endif
PRINT_PLIST_AWK+=	/dmx/ { print "$${DMX}" $$0; next }

PLIST_VARS+=		gdmopen
.if exists(/usr/include/linux/vt.h) || ${OPSYS} == "SunOS"
PLIST.gdmopen=		yes
.endif
PRINT_PLIST_AWK+=	/gdmopen/ { print "$${GDMOPEN}" $$0; next }

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gdm/BuiltInSessions
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${DESTDIR}${PREFIX}/share/gdm/BuiltInSessions

.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../security/openpam/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
