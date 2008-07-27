# $NetBSD: Makefile,v 1.3 2008/07/27 12:03:58 plunky Exp $

DISTNAME=		netbt-hcidump-1.42
CATEGORIES=		sysutils
MASTER_SITES=		http://bluez.sourceforge.net/download/
DISTFILES=		bluez-hcidump-1.42.tar.gz	\
			bluez-libs-3.35.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

WRKSRC=			${WRKDIR}/bluez-hcidump-1.42
LIBSRC=			${WRKDIR}/bluez-libs-3.35

PKG_OPTIONS_VAR=	PKG_OPTIONS.hcidump
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=		-DINET6
.endif

CPPFLAGS+=	-DVERSION=\""1.42-netbt"\"

USE_BSD_MAKEFILE=	yes

post-extract:
	mkdir ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/bluetooth.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/hci.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/hci_lib.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/include/l2cap.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/src/bluetooth.c ${WRKSRC}/src/bt_lib.c
	cp ${LIBSRC}/src/hci.c ${WRKSRC}/src/hci_lib.c

.include "../../mk/bsd.pkg.mk"
