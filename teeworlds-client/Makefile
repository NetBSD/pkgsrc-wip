# $NetBSD: Makefile,v 1.1.1.1 2010/06/29 14:13:23 hftmarkand Exp $

.include "../teeworlds/Makefile.common"

PKGNAME=	teeworlds-client-${TEEWORLDS_VERSION}
CONFLICTS+=	teeworlds-[0-9]*
CONFLICTS+=	teeworlds-server-[0-9]*

# Use the same settings.
DISTINFO_FILE=	${.CURDIR}/../teeworlds/distinfo
PATCHDIR=	${.CURDIR}/../teeworlds/patches
DESCR_SRC=	${.CURDIR}/../teeworlds/DESCR
FILESDIR=	${.CURDIR}/../teeworlds/files

# Only for client side.
SUBST_STAGE.default-bam=        pre-build
SUBST_MESSAGE.default-bam=      Fixing default bam for python and X libs
SUBST_FILES.default-bam=        ${TEEWORLDS_WRKSRC}/default.bam
SUBST_SED.default-bam=          -e 's,@PYTHONBIN@,${PYTHONBIN},; s,@CFLAGS@,${CFLAGS},; s,@X11BASE@,${X11BASE},g'

# Change the desktop file icon.
SUBST_CLASSES+=                 desktop
SUBST_STAGE.desktop=            post-install
SUBST_MESSAGE.desktop=          Fixing the icon location in desktop entry.
SUBST_FILES.desktop=            ${DESTDIR}${APPSDIR}/teeworlds.desktop
SUBST_SED.desktop=              -e 's,@DATADIR@,${DESTDIR}${DATADIR},'

# We want client only target.
BAM_TARGET=	client_release

APPSDIR=                ${PREFIX}/share/applications
INSTALLATION_DIRS+=     ${APPSDIR}

do-build:
	cd ${BAM_WRKSRC} && sh make_unix.sh
	cd ${TEEWORLDS_WRKSRC} && ${BAM_WRKSRC}/src/bam -v ${BAM_TARGET}

do-install:
	${INSTALL_PROGRAM} ${TEEWORLDS_WRKSRC}/teeworlds ${DESTDIR}${PREFIX}/bin

	cd ${TEEWORLDS_WRKSRC}/data && ${PAX} -rw . ${DESTDIR}${DATADIR}

	${INSTALL_DATA} ${TEEWORLDS_WRKSRC}/other/icons/Teeworlds.ico ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/teeworlds.desktop ${DESTDIR}${APPSDIR}

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
