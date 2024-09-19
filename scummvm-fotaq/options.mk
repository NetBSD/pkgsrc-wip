# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.scummvm-fotaq-0
PKG_SUPPORTED_OPTIONS+=		cd floppy lang-de lang-fr
PKG_OPTIONS_REQUIRED_GROUPS=	media
PKG_OPTIONS_GROUP.media=	cd floppy lang-de lang-fr
PKG_SUGGESTED_OPTIONS=		cd
PLIST_VARS+=			cd floppy

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcd)
DISTNAME=	FOTAQ_Talkie-1.1
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1c ${DESTDIR}${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${DESTDIR}${PREFIX}/bin/fotaq
PLIST.cd=	yes
.endif

.if !empty(PKG_OPTIONS:Mfloppy)
DISTNAME=	FOTAQ_Floppy
WRKSRC=		${WRKDIR}/FOTAQ_Floppy
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1 ${DESTDIR}${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${DESTDIR}${PREFIX}/bin/fotaq
PLIST.floppy=	yes
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DISTNAME=	FOTAQ_Ger_talkie-1.0
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1c ${DESTDIR}${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${DESTDIR}${PREFIX}/bin/fotaq
PLIST.cd=	yes
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DISTNAME=	FOTAQ_Fr_Talkie_1.0
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FOTAQDIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1c ${DESTDIR}${FOTAQDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/fotaq.sh ${DESTDIR}${PREFIX}/bin/fotaq
PLIST.cd=	yes
.endif
