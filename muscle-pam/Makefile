# $NetBSD: Makefile,v 1.5 2012/10/03 15:09:59 asau Exp $

DISTNAME=		muscleframework-1.1.5
PKGNAME=		muscle-pam-1.1.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/463/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.linuxnet.com/
COMMENT=	PAM plugin for MUSCLE SmartCard framework


WRKSRC=			${WRKDIR}/${DISTNAME}/MusclePAM
USE_TOOLS+=		gmake

CPPFLAGS+=		-I${LOCALBASE}/include/PCSC

PKG_SYSCONFSUBDIR=	musclepam
EGDIR=			${PREFIX}/share/examples/muscle-pam
CONF_FILES=		${EGDIR}/pam-muscle.conf ${PKG_SYSCONFDIR}/pam-muscle.conf

SUBST_CLASSES+=		prefs
SUBST_STAGE.prefs=	pre-build
SUBST_FILES.prefs=	preferences.c
SUBST_SED.prefs=	-e 's|/etc|${PKG_SYSCONFDIR}|g'

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pam-muscle.conf ${EGDIR}

.include "../../mk/pam.buildlink3.mk"
.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
