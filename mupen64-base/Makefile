# $NetBSD: Makefile,v 1.14 2012/10/03 14:50:41 asau Exp $
#

DISTNAME=	mupen64_src-0.4
PKGNAME=	${DISTNAME:S/_src/-base/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Free Nintendo 64(TM) emulator for unix-like OS

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/emu64

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	Makefile
SUBST_SED.fixme=	-e "s|@BLNK@|${BUILDLINK_DIR}|g" \
			-e "s|@LDFLAGS@|${LDFLAGS}|g"

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/lang
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/roms
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/save
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mupen64 ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/lang/* ${DESTDIR}${SHAREDIR}/lang
	${INSTALL_DATA} ${WRKSRC}/mupen64.ini ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xpm ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.pdf ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/roms/*.gz ${DESTDIR}${SHAREDIR}/roms
	${SED} -e "s,@SHAREDIR@,${SHAREDIR},g" ${FILESDIR}/mupen64.sh > \
	    ${WRKSRC}/roms/mupen64
	${INSTALL_SCRIPT} ${WRKSRC}/roms/mupen64 ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
