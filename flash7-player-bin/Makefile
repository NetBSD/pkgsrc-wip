# $NetBSD: Makefile,v 1.1.1.1 2004/06/01 03:00:08 cetrox Exp $
#

DISTNAME=		install_flash_player_7_linux
PKGNAME=                flash7-player-bin-7.0.25.0
CATEGORIES=		wip multimedia
MASTER_SITES=		http://fpdownload.macromedia.com/get/shockwave/flash/english/linux/7.0r25/

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://www.macromedia.com/
COMMENT=		Macromedia flash 7 player binary

RESTRICTED=             "Redistribution not permitted"
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

NO_BUILDLINK=		yes
NO_CONFIGURE=           yes
NO_BUILD=               yes
CHECK_SHLIBS=           no
CRYPTO=                 yes

NS_PLUGINS_DIR=         ${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/flashplayer.xpt ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.if defined(OPSYS) && ${OPSYS} != "SunOS"
.include "../../emulators/suse_linux/Makefile.application"
.endif                   

.include "../../mk/bsd.pkg.mk"
