# $NetBSD: Makefile,v 1.1.1.1 2005/10/26 19:26:25 ghen Exp $

DISTNAME=		install_flash_player_7_linux
VERSION=		7.0r25
PKGNAME=		opera-flash-${VERSION:S/r/./}
CATEGORIES=		multimedia www
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/english/linux/${VERSION}/

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://www.macromedia.com/
COMMENT=		Flash player for the Linux version of Opera (binary pkg)

ONLY_FOR_PLATFORM=	*-*-i386

RESTRICTED=             "Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=		opera-[0-9]*:../../www/opera

# XXX opera should depend on emulators/suse*_openmotif (PR#31882),
#     but in the meantime we'll depend on it here.
.include "../../emulators/suse_linux/Makefile.application"
DEPENDS+=		suse_openmotif>=7.3:../../emulators/${SUSE_DIR_PREFIX}_openmotif

NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}/install_flash_player_7_linux

PLUGINDIR=		emul/linux/usr/lib/opera/plugins
DOCDIR=			share/doc/opera-flash
PLIST_SUBST+=		DOCDIR="${DOCDIR}"
PLIST_SUBST+=		PLUGINDIR="${PLUGINDIR}"

INSTALLATION_DIRS=	${PLUGINDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libflashplayer.so ${PREFIX}/${PLUGINDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/Readme.txt ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.htm ${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
