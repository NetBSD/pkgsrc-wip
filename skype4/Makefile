# $NetBSD: Makefile,v 1.3 2015/04/01 16:23:09 tnn2 Exp $

DISTNAME=		skype-4.3.0.37
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software (4.x branch)
LICENSE=		skype21-license

RESTRICTED=		Complex terms for redistribution.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_REQD=		suse>=13.1
EMUL_MODULES.linux=	alsa base glx gstreamer gtk2 qt4 sqlite3 x11 xml2 xslt webp

DATADIR=		share/skype
DOCDIR=			share/doc/skype

INSTALLATION_DIRS+=	bin share/applications ${DOCDIR}
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	${DATADIR}/avatars ${DATADIR}/icons ${DATADIR}/sounds

do-build:
	set -e; \
	{ ${ECHO} "#!${SH}"; \
		${ECHO} 'exec ${PREFIX}/${DATADIR}/skype --resources=${PREFIX}/${DATADIR} "$$@"'; \
	} > ${WRKSRC}/skype.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skype.sh ${DESTDIR}${PREFIX}/bin/skype
	${INSTALL_DATA} ${WRKSRC}/skype.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_16x16.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/skype.png
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_32x32.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/skype.png
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/skype.png
	${INSTALL_SCRIPT} ${WRKSRC}/skype ${DESTDIR}${PREFIX}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/avatars/*.png \
		${DESTDIR}${PREFIX}/${DATADIR}/avatars
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DESTDIR}${PREFIX}/${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${DESTDIR}${PREFIX}/${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
