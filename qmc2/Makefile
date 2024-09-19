# $NetBSD: Makefile,v 1.3 2014/01/02 19:36:06 thomasklausner Exp $

DISTNAME=	qmc2-0.42
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qmc2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qmc2.arcadehits.net/wordpress/
COMMENT=	Multi-platform GUI front end for MAME and MESS
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/qmc2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
QMAKE=		${QTDIR}/bin/qmake

EGDIR=		${PREFIX}/share/examples/qmc2
CONF_FILES+=	${EGDIR}/qmc2.ini ${PKG_SYSCONFDIR}/qmc2/qmc2.ini

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/${PKGBASE} ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_MESSAGE.paths=	Fixing PREFIX and PKG_SYSCONFDIR paths.
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|/etc|${PKG_SYSCONFDIR}|1"
SUBST_STAGE.paths=	pre-install

.include "options.mk"

#pre-install:
#		${INSTALL_DATA} ${WRKSRC}/data/lightdm-gtk-greeter.conf ${DESTDIR}${EGDIR}/lightdm-gtk-greeter.conf


do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} DISTCFG=1 QMAKE=${QMAKE} EMULATOR=${EMULATOR}

do-install:
	cd ${WRKSRC} && \
		${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET} DISTCFG=1 QMAKE=${QMAKE} EMULATOR=${EMULATOR}

post-install:
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/qmc2/qmc2.ini \
		${DESTDIR}${EGDIR}/
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/qmc2/qmc2.ini
	${RM} -fr ${DESTDIR}${PREFIX}/share/qmc2/*/*/*/PaxHeaders*
	${RM} -fr ${DESTDIR}${PREFIX}/share/qmc2/*/*/PaxHeaders*
	${RM} -fr ${DESTDIR}${PREFIX}/share/qmc2/*/PaxHeaders*
	${RM} -fr ${DESTDIR}${PREFIX}/share/qmc2/PaxHeaders*

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
