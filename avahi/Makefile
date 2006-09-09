# $NetBSD: Makefile,v 1.1.1.1 2006/09/09 13:13:47 adrian_p Exp $
#

DISTNAME=		avahi-0.6.10
CATEGORIES=		net
MASTER_SITES=		http://avahi.org/download/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://avahi.org/
COMMENT=		Facilitate service discovery on a local network

USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/avahi-core.pc.in
GNU_CONFIGURE=		YES
AVAHI_USER=		avahi
AVAHI_GROUP=		avahi
RCD_SCRIPTS=		avahidaemon
USE_PKGINSTALL=		YES
BUILD_DEFS=		VARBASE

PKG_USERS=		${AVAHI_USER}:${AVAHI_GROUP}::Avahi\ user:/nonexistent
PKG_GROUPS=		${AVAHI_GROUP}

CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-daemon.conf \
			${PKG_SYSCONFDIR}/avahi/avahi-daemon.conf
CONF_FILES+=		${PREFIX}/share/examples/avahi/hosts \
			${PKG_SYSCONFDIR}/avahi/hosts
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dnsconfd.action \
			${PKG_SYSCONFDIR}/avahi/avahi-dnsconfd.action
CONF_FILES+=		${PREFIX}/share/examples/avahi/ssh.service \
			${PKG_SYSCONFDIR}/avahi/services/ssh.service

CONFIGURE_ARGS+=	--with-avahi-user=${AVAHI_USER:Q}
CONFIGURE_ARGS+=	--with-avahi-group=${AVAHI_GROUP:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-dbus
CONFIGURE_ARGS+=	--disable-glib
CONFIGURE_ARGS+= 	--disable-qt3
CONFIGURE_ARGS+= 	--disable-qt4
CONFIGURE_ARGS+= 	--disable-gtk
CONFIGURE_ARGS+= 	--disable-gdbm
CONFIGURE_ARGS+= 	--disable-python
CONFIGURE_ARGS+= 	--disable-mono
CONFIGURE_ARGS+= 	--disable-monodoc
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--disable-doxygen-dot
CONFIGURE_ARGS+=	--disable-doxygen-html
CONFIGURE_ARGS+=	--disable-xmltoman

.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/libdaemon/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/avahi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avahi
	${INSTALL_DATA_DIR} ${PREFIX}/etc/avahi/services

	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/avahi-daemon.conf \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/hosts \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-dnsconfd/avahi-dnsconfd.action \
		${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/ssh.service \
		${PREFIX}/share/examples/avahi

	${INSTALL_DATA} ${WRKSRC}/docs/HACKING ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/README ${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${PREFIX}/share/doc/avahi

.include "../../mk/bsd.pkg.mk"
