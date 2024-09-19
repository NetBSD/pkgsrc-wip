# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.scummvm-bass-0
PKG_SUPPORTED_OPTIONS+=		cd floppy
PKG_OPTIONS_REQUIRED_GROUPS=	media
PKG_OPTIONS_GROUP.media=	cd floppy
PKG_SUGGESTED_OPTIONS=		cd
PLIST_VARS+=			cd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcd)
DISTNAME=	bass-cd-1.2
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BASSDIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${WRKSRC}/sky.cpt ${WRKSRC}/sky.dsk ${DESTDIR}${BASSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bass.sh ${DESTDIR}${PREFIX}/bin/bass
PLIST.cd=	yes
.endif

.if !empty(PKG_OPTIONS:Mfloppy)
DISTNAME=	BASS-Floppy-1.3
WRKSRC=		${WRKDIR}
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BASSDIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${WRKSRC}/sky.dsk ${DESTDIR}${BASSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bass.sh ${DESTDIR}${PREFIX}/bin/bass
.endif
