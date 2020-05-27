# $NetBSD: Makefile,v 1.4 2014/07/18 11:10:22 fhajny Exp $
#

DISTNAME=	spread-src-4.4.0
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	SPREAD_DIR SPREAD_USER SPREAD_GROUP

PKG_GROUPS_VARS=	SPREAD_GROUP
PKG_USERS_VARS=		SPREAD_USER

PKG_GROUPS=	${SPREAD_USER}
PKG_USERS=	${SPREAD_USER}:${SPREAD_GROUP}

SPREAD_USER=	spread
SPREAD_GROUP=	spread
SPREAD_DIR?=	${VARBASE}/run/spread

OWN_DIRS_PERMS=	${SPREAD_DIR} ${SPREAD_USER} ${SPREAD_GROUP} 0750

FILES_SUBST+=	SPREAD_USER=${SPREAD_USER}
FILES_SUBST+=	SPREAD_GROUP=${SPREAD_GROUP}
FILES_SUBST+=	SPREAD_DIR=${SPREAD_DIR}

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/spread
CONFIGURE_ARGS+=	--with-pid-dir=${SPREAD_DIR}
MAKE_FLAGS+=		LD=${CC:Q}

RCD_SCRIPTS=		spread
DOCSDIR=		${PREFIX}/share/doc/spread
EXAMPLEDIR=		${PREFIX}/share/examples/spread
INSTALLATION_DIRS+=	${DOCSDIR} ${EXAMPLEDIR}

CONF_FILES=	${EXAMPLEDIR}/spread.access_ip ${PKG_SYSCONFDIR}/spread.access_ip
CONF_FILES+=	${EXAMPLEDIR}/spread.conf ${PKG_SYSCONFDIR}/spread.conf

SUBST_CLASSES+=		spread
SUBST_STAGE.spread=	pre-configure
SUBST_MESSAGE.spread=	Fix default config
SUBST_FILES.spread=	daemon/spread_params.h
SUBST_FILES.spread+=	docs/sample.spread.conf docs/spread.1 docs/spmonitor.1
SUBST_VARS.spread=	SPREAD_USER SPREAD_GROUP SPREAD_DIR PKG_SYSCONFDIR

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.access_ip ${DESTDIR}${EXAMPLEDIR}/spread.access_ip

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
