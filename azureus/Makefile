# $NetBSD: Makefile,v 1.1.1.1 2006/09/01 21:34:32 dhowland Exp $
#

DISTNAME=		azureus-2.5.0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=azureus/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		Azureus_2.5.0.0_linux.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://azureus.sourceforge.net/
COMMENT=		Bittorrent client written in java

DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		suse_gtk2>=10.0:../../emulators/suse100_gtk2

NO_BUILD=		yes

WRKSRC=			${WRKDIR}/azureus

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_MESSAGE.prefix=	Fixing prefixes.
SUBST_FILES.prefix=	azureus
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/azureus ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/azureus
	${INSTALL} ${WRKSRC}/*.png ${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.jar ${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.txt ${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.so ${PREFIX}/share/azureus/
	${INSTALL} ${WRKSRC}/*.html ${PREFIX}/share/azureus/
	${INSTALL_DATA_DIR} ${PREFIX}/share/azureus/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/azureus/plugins/azplugins
	${INSTALL} ${WRKSRC}/plugins/azplugins/*.jar ${PREFIX}/share/azureus/plugins/azplugins/
	${INSTALL_DATA_DIR} ${PREFIX}/share/azureus/plugins/azrating
	${INSTALL} ${WRKSRC}/plugins/azrating/*.jar ${PREFIX}/share/azureus/plugins/azrating/
	${INSTALL_DATA_DIR} ${PREFIX}/share/azureus/plugins/azupdater
	${INSTALL} ${WRKSRC}/plugins/azupdater/*.jar ${PREFIX}/share/azureus/plugins/azupdater/
	${INSTALL} ${WRKSRC}/plugins/azupdater/*.properties ${PREFIX}/share/azureus/plugins/azupdater/

.include "../../lang/sun-jre15/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
