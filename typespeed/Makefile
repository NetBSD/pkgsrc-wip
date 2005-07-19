# $NetBSD: Makefile,v 1.3 2005/07/19 18:44:00 h2m Exp $
#

DISTNAME=		typespeed-0.4.4
PKGREVISION=		1
CATEGORIES=		wip games
MASTER_SITES=		http://ls.purkki.org/typespeed/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://ls.purkki.org/typespeed/
COMMENT=		Game to measure your typing speed, with network mode

MAKEFILE=		${FILESDIR}/Makefile

CONF_FILES=		${PKG_SYSCONFDIR}/typespeedrc

pre-patch:
	${MV} ${WRKSRC}/typespeed.1 ${WRKSRC}/typespeed.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/typespeed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/typespeed.cat6 ${PREFIX}/man/cat6/typespeed.0
	${INSTALL_MAN} ${WRKSRC}/typespeed.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/typespeed
	${INSTALL_DATA} ${WRKSRC}/words.* ${PREFIX}/share/typespeed

	cd ${PREFIX}/share/typespeed && ${PREFIX}/bin/typespeed --makescore
	${ECHO} ${PREFIX}/share/typespeed/ > ${PKG_SYSCONFDIR}/typespeedrc

SUBST_CLASSES=		datapath etcpath man
SUBST_STAGE.etcpath=	post-patch
SUBST_FILES.etcpath=	typespeed.6 typespeed.h
SUBST_SED.etcpath=	-e 's|/etc/typespeedrc|${PKG_SYSCONFDIR}/typespeedrc|g'
SUBST_MESSAGE.etcpath=	"Adjusting the etc path."
SUBST_STAGE.datapath=	post-patch
SUBST_FILES.datapath=	typespeed.6
SUBST_SED.datapath=	-e 's|/usr/local/lib|${PREFIX}/share|g'
SUBST_MESSAGE.datapath=	"Adjusting the data path."
SUBST_STAGE.man=    	post-patch
SUBST_FILES.man=    	typespeed.6
SUBST_SED.man=      	-e 's|TYPESPEED 1|TYPESPEED 6|g'
SUBST_MESSAGE.man=  	"Adjusting man page section, from section 1 to 6."

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
