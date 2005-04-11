# $NetBSD: Makefile,v 1.5 2005/04/11 21:14:09 tvierling Exp $
#

DISTNAME=	mupen64_src-0.4
PKGNAME=	${DISTNAME:S/_src/-base/}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Free Nintendo 64(TM) emulator for unix-like OS 

USE_GNU_TOOLS+=	make
USE_X11=	yes
WRKSRC=		${WRKDIR}/emu64

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

SUBST_CLASSES=	    fixme
SUBST_STAGE.fixme=  post-patch
SUBST_FILES.fixme=  Makefile
SUBST_SED.fixme=    -e "s|@BLNK@|${BUILDLINK_DIR}|g" \
		    -e "s|@LDFLAGS@|${LDFLAGS}|g"

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
SHAREDIR=	${PREFIX}/share/${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}/lang
	${INSTALL_DATA_DIR} ${SHAREDIR}/roms
	${INSTALL_DATA_DIR} ${SHAREDIR}/scripts
	${INSTALL_DATA_DIR} ${SHAREDIR}/save
	${INSTALL_DATA_DIR} ${SHAREDIR}/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mupen64 ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/lang/* ${SHAREDIR}/lang
	${INSTALL_DATA} ${WRKSRC}/mupen64.ini ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xpm ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.pdf ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/roms/*.gz ${SHAREDIR}/roms
	${SED} -e "s,@SHAREDIR@,${SHAREDIR},g" ${FILESDIR}/mupen64.sh > \
	    ${WRKSRC}/roms/mupen64
	${INSTALL_SCRIPT} ${WRKSRC}/roms/mupen64 ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
