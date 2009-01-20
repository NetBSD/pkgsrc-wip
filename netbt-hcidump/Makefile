# $NetBSD: Makefile,v 1.7 2009/01/20 17:51:45 plunky Exp $

DISTNAME=		netbt-hcidump-1.42
CATEGORIES=		sysutils
MASTER_SITES=		http://bluez.sourceforge.net/download/	\
			http://www.kernel.org/pub/linux/bluetooth/
DISTFILES=		bluez-hcidump-1.42.tar.gz	\
			bluez-4.27.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

WRKSRC=			${WRKDIR}/bluez-hcidump-1.42
LIBSRC=			${WRKDIR}/bluez-4.27

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_OPTIONS_VAR=	PKG_OPTIONS.hcidump
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

CPPFLAGS+=	-DVERSION=\""1.42-netbt"\"

USE_BSD_MAKEFILE=	yes

post-extract:
	mkdir ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/bluetooth.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/hci.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/hci_lib.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/l2cap.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/bluetooth.c ${WRKSRC}/src/bt_lib.c
	cp ${LIBSRC}/lib/hci.c ${WRKSRC}/src/hci_lib.c

.include "../../mk/bsd.pkg.mk"
