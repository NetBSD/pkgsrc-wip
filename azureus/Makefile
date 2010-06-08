# $NetBSD: Makefile,v 1.5 2010/06/08 16:14:56 thomasklausner Exp $
#

DISTNAME=		azureus-2.2.0.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=azureus/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		Azureus_2.2.0.2_linux.GTK.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://azureus.sourceforge.net/
COMMENT=		Bittorrent client written in java

DEPENDS+=		bash-[0-9]*:../../shells/bash

EMUL_PLATFORMS=		linux-i386
NOT_FOR_PLATFORM=	NetBSD-[0-2]*-*

EMUL_MODULES.linux=	gtk2
SUSE_VERSION_REQD=	10.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/azureus
BUILD_DIRS=		# empty

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_MESSAGE.prefix=	Fixing prefixes.
SUBST_FILES.prefix=	azureus
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/azureus ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/azureus
	${INSTALL} ${WRKSRC}/*.png ${DESTDIR}${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.so ${DESTDIR}${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.html ${DESTDIR}${PREFIX}/share/azureus/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/azureus/plugins
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/azureus/plugins/azplugins
	${INSTALL} ${WRKSRC}/plugins/azplugins/*.jar ${DESTDIR}${PREFIX}/share/azureus/plugins/azplugins/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/azureus/plugins/azupdater
	${INSTALL} ${WRKSRC}/plugins/azupdater/*.jar ${DESTDIR}${PREFIX}/share/azureus/plugins/azupdater/
	${INSTALL} ${WRKSRC}/plugins/azupdater/*.properties ${DESTDIR}${PREFIX}/share/azureus/plugins/azupdater/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
