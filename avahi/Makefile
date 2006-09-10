# $NetBSD: Makefile,v 1.2 2006/09/10 18:29:58 adrian_p Exp $

DISTNAME=		avahi-0.6.10
CATEGORIES=		net
MASTER_SITES=		http://avahi.org/download/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://avahi.org/
COMMENT=		Facilitate service discovery on a local network

USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	avahi-core.pc.in
GNU_CONFIGURE=		YES
AVAHI_USER=		avahi
AVAHI_GROUP=		avahi
RCD_SCRIPTS=		avahidaemon
USE_PKGINSTALL=		YES
BUILD_DEFS=		VARBASE
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PKG_SYSCONFSUBDIR=	avahi

PKG_USERS=		${AVAHI_USER}:${AVAHI_GROUP}::Avahi\ user:/nonexistent
PKG_GROUPS=		${AVAHI_GROUP}

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST.shared

CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-daemon.conf \
			${PKG_SYSCONFDIR}/avahi-daemon.conf
CONF_FILES+=		${PREFIX}/share/examples/avahi/hosts \
			${PKG_SYSCONFDIR}/hosts
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dnsconfd.action \
			${PKG_SYSCONFDIR}/avahi-dnsconfd.action
CONF_FILES+=		${PREFIX}/share/examples/avahi/ssh.service \
			${PKG_SYSCONFDIR}/services/ssh.service

.if !empty(PKG_OPTIONS:Mdbus)
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dbus.conf \
			${PREFIX}/etc/dbus-1/system.d/avahi-dbus.conf
.endif

CONFIGURE_ARGS+=	--with-avahi-user=${AVAHI_USER:Q}
CONFIGURE_ARGS+=	--with-avahi-group=${AVAHI_GROUP:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+= 	--disable-qt3
CONFIGURE_ARGS+= 	--disable-qt4
CONFIGURE_ARGS+= 	--disable-mono
CONFIGURE_ARGS+= 	--disable-monodoc
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--disable-doxygen-dot
CONFIGURE_ARGS+=	--disable-doxygen-html
CONFIGURE_ARGS+=	--disable-xmltoman

.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/libdaemon/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-extract:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/avahi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avahi
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/services

	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/avahi-daemon.conf \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/hosts \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-dnsconfd/avahi-dnsconfd.action \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/ssh.service \
		${PREFIX}/share/examples/avahi

.	if !empty(PKG_OPTIONS:Mdbus)
		${INSTALL_DATA} ${WRKSRC}/avahi-daemon/avahi-dbus.conf \
			${PREFIX}/share/examples/avahi/avahi-dbus.conf
.	endif

	${INSTALL_DATA} ${WRKSRC}/docs/HACKING ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/README ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${PREFIX}/share/doc/avahi

.include "../../mk/bsd.pkg.mk"
