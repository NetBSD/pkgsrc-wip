# $NetBSD: Makefile,v 1.2 2013/05/27 13:35:28 fhajny Exp $
#

DISTNAME=	pgpool-II-3.2.4
PKGNAME=	postgresql${PGSQL_VERSION}-pgpool2-${DISTNAME:S/pgpool-II-//}
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.pgpool.net/mediawiki/
COMMENT=	Middleware between PostgreSQL servers and a PostgreSQL database client
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "options.mk"
.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=		PGPOOL_USER PGPOOL_GROUP PGGROUP PGHOME VARBASE

EGDIR=			share/examples/pgpool2

PGPOOL_USER?=		pgpool
PGPOOL_GROUP?=		${PGGROUP}
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGGROUP}

PKG_GROUPS=		${PGPOOL_GROUP}
PKG_USERS=		${PGPOOL_USER}:${PGPOOL_GROUP}
PKG_GROUPS_VARS+=	PGPOOL_GROUP
PKG_USERS_VARS=		PGPOOL_USER
PKG_HOME.${PGPOOL_USER}=	${PGHOME}
PKG_SHELL.${PGPOOL_GROUP}=	${SH}

PKG_SYSCONFSUBDIR=	pgpool2
PGPOOL_PIDDIR?=		${VARBASE}/run/pgpool
OWN_DIRS_PERMS+=	${PGPOOL_PIDDIR} ${PGPOOL_USER} ${PGPOOL_GROUP} 0751

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing default paths
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	pgpool.conf.sample pool.h
SUBST_VARS.path=	PGPOOL_PIDDIR

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES+=	${EGDIR}/pcp.conf.sample ${PKG_SYSCONFDIR}/pcp.conf
CONF_FILES+=	${EGDIR}/pgpool.conf.sample ${PKG_SYSCONFDIR}/pgpool.conf
CONF_FILES+=	${EGDIR}/pool_hba.conf.sample ${PKG_SYSCONFDIR}/pool_hba.conf
CONF_FILES_PERMS+=	${EGDIR}/pool_passwd ${PKG_SYSCONFDIR}/pool_passwd \
			${PGPOOL_USER} ${PGGROUP} 0640

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/pgpool2/pool_passwd

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
