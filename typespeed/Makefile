# $NetBSD: Makefile,v 1.8 2006/04/20 13:36:44 cheusov Exp $
#

DISTNAME=		typespeed-0.4.4
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://ls.purkki.org/typespeed/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://ls.purkki.org/typespeed/
COMMENT=		Game to measure your typing speed, with network mode

MAKEFILE=		${FILESDIR}/Makefile

pre-patch:
	${MV} ${WRKSRC}/typespeed.1 ${WRKSRC}/typespeed.6

post-patch:
	${CP} ${FILESDIR}/typespeed ${WRKDIR}/.typespeed

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/typespeed
	${INSTALL_PROGRAM} ${WRKSRC}/typespeed ${PREFIX}/lib/typespeed
	${INSTALL_SCRIPT} ${WRKDIR}/.typespeed ${PREFIX}/bin/typespeed
	${INSTALL_MAN} ${WRKSRC}/typespeed.cat6 ${PREFIX}/${PKGMANDIR}/cat6/typespeed.0
	${INSTALL_MAN} ${WRKSRC}/typespeed.6 ${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/typespeed
	${INSTALL_DATA} ${WRKSRC}/words.* ${PREFIX}/share/typespeed

SUBST_CLASSES+=		sharepath etcpath execscript1 execscript2 man
SUBST_STAGE.etcpath=	post-patch
SUBST_FILES.etcpath=	typespeed.6 typespeed.h
SUBST_SED.etcpath=	-e 's|/etc/typespeedrc|${PKG_SYSCONFDIR}/typespeedrc|g'
SUBST_MESSAGE.etcpath=	Adjusting etc path
SUBST_STAGE.sharepath=	post-patch
SUBST_FILES.sharepath=	typespeed.6
SUBST_SED.sharepath=	-e 's|/usr/local/lib|${PREFIX}/share|g'
SUBST_MESSAGE.sharepath=Adjusting data path
SUBST_STAGE.man=    	post-patch
SUBST_FILES.man=    	typespeed.6
SUBST_SED.man=      	-e 's|TYPESPEED 1|TYPESPEED 6|g'
SUBST_MESSAGE.man=  	"Adjusting man page section, from section 1 to 6"
SUBST_STAGE.execscript1=pre-install
SUBST_FILES.execscript1=${WRKDIR}/.typespeed
SUBST_SED.execscript1=	-e 's|LIBPATH|${PREFIX}/lib/typespeed|g'
SUBST_MESSAGE.execscript1=Setting typespeed lib path in execution script
SUBST_STAGE.execscript2=pre-install
SUBST_FILES.execscript2=${WRKDIR}/.typespeed
SUBST_SED.execscript2=	-e 's|SHAREPATH|${PREFIX}/share/typespeed|g'
SUBST_MESSAGE.execscript2=Setting typespeed share path in execution script

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
