# $NetBSD$
#

DISTNAME=		nats-server-2.1.8
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=nats-io/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		https://nats.io/
COMMENT=		Simple, secure and high performance messaging system
LICENSE=		apache-2.0

GO_BUILD_PATTERN=	.

NATS_USER=		natssrv
NATS_GROUP=		natssrv
NATS_HOMEDIR=		${VARBASE}/nats-server
NATS_LOGDIR=		${VARBASE}/log/nats-server
NATS_LOGFILE=		${NATS_LOGDIR}/nats-server.log

CHECK_SSP_SKIP=		bin/*

.include "go-modules.mk"

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=     ${NATS_GROUP}
PKG_USERS=      ${NATS_USER}:${NATS_GROUP}

PKG_HOME.${NATS_USER}=        ${NATS_HOMEDIR}
PKG_GECOS.${NATS_USER}=      nats.io server

RCD_SCRIPTS=            nats-server
SMF_NAME=               nats-server
SMF_METHODS=            ${RCD_SCRIPTS}

FILES_SUBST+=		NATS_USER=${NATS_USER}
FILES_SUBST+=		NATS_GROUP=${NATS_GROUP}
FILES_SUBST+=		NATS_HOMEDIR=${NATS_HOMEDIR}
FILES_SUBST+=		NATS_LOGDIR=${NATS_LOGDIR}
FILES_SUBST+=		NATS_LOGFILE=${NATS_LOGFILE}

OWN_DIRS_PERMS+=                ${NATS_HOMEDIR} ${NATS_USER} ${NATS_GROUP} 0700
MAKE_DIRS_PERMS+=                ${NATS_LOGDIR} ${NATS_USER} ${NATS_GROUP} 0700

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
