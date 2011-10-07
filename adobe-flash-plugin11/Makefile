# $NetBSD: Makefile,v 1.1.1.1 2011/10/07 08:59:38 ryo-on Exp $

PKGNAME=		adobe-flash-plugin-${FLASH_VERSION:S/r/./}
CATEGORIES=		multimedia www
MASTER_SITES=		http://fpdownload.macromedia.com/get/flashplayer/current/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.adobe.com/
COMMENT=		Adobe Flash Player Browser plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	NetBSD-*-[0-4]* NetBSD-*-5.[0-9].*

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
EXTRACT_SUFX=		.rpm

CRYPTO=			yes

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	gtk2 x11 krb5 alsa curl
EMUL_REQD=		suse>=11.3

FLASH_VERSION=		11.0.1.152

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		flash-plugin-${FLASH_VERSION}-release.i386
.elif ${EMUL_PLATFORM} == "linux-x86_64"
DISTNAME=		flash-plugin-${FLASH_VERSION}-release.x86_64
.endif

CONFLICTS=		ns-flash-[0-9]*

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/usr/lib/flash-plugin/libflashplayer.so \
		${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
