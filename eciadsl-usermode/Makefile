# $NetBSD: Makefile,v 1.9 2012/09/28 21:36:21 asau Exp $
#

DISTNAME=		eciadsl-usermode-0.10
CATEGORIES=		net
MASTER_SITES=		http://benoit.is-a-geek.net/bsd-tmp/

MAINTAINER=		imil@gcu.info
COMMENT=		Driver for Globespan chipset-based ADSL USB modems

BUILD_DEPENDS+=		userppp>=001107:../../net/userppp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386

CHECK_PORTABILITY_SKIP=	configure.sav

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
BUILD_TARGET=		eci-load1 eci-load2 pppoeci

pre-build:
	cd ${WRKSRC} && gmake clean # archive's dirty

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ppp.conf ${PKG_SYSCONFDIR}/ppp/ppp.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/eci-load1 ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/eci-load2 ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/pppoeci ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/modems.db ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/providers.db ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/firmware00.bin ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/synch01.bin ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ppp.conf ${DESTDIR}${EGDIR}

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Setting up hardcoded path
# this archive is really dirty, config.h is not created by configure...
SUBST_FILES.path=	Makefile.dep config.h				\
			check-hdlc-bug.c check-hdlc.c eci-load1.c	\
			eci-load2.c pppoeci.c semaphore.c
SUBST_STAGE.path=	post-patch
SUBST_SED.path=		-e 's|/usr/pkg|${PREFIX}|'

SUBST_CLASSES+=		ppp_conf
SUBST_FILES.ppp_conf=	ppp.conf
SUBST_STAGE.ppp_conf=	post-patch
SUBST_SED.ppp_conf=	-e 's|/root/eciadsl-usermode-0.10|${PREFIX}/sbin|'

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "../../wip/libpusb/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
