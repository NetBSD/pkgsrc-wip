# $NetBSD: Makefile,v 1.5 2004/09/22 16:18:25 shattered Exp $
#

DISTNAME=		bacula-1.34.6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Network Backup Solution

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR?=	bacula
BACULA_PIDDIR?=		/var/run/bacula
BACULA_WORKINGDIR?=	/var/spool/bacula
BACULA_GROUP?=		bacula
BACULA_DIR_USER?=	bacula-dir
BACULA_SD_USER?=	bacula-sd

OWN_DIRS_PERMS=		${BACULA_PIDDIR} root ${BACULA_GROUP} 770
OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} root ${BACULA_GROUP} 770

FILES_SUBST+=		BACULA_ETCDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=		BACULA_PIDDIR=${BACULA_PIDDIR}
FILES_SUBST+=		BACULA_GROUP=${BACULA_GROUP}
FILES_SUBST+=		BACULA_DIR_USER=${BACULA_DIR_USER}
FILES_SUBST+=		BACULA_SD_USER=${BACULA_SD_USER}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/libexec/bacula
CONFIGURE_ARGS+=	--with-working-dir=${BACULA_WORKINGDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${BACULA_PIDDIR}
CONFIGURE_ARGS+=	--with-readline=${PREFIX}/include/readline
CONFIGURE_ARGS+=	--with-dir-user=${BACULA_DIR_USER} --with-dir-group=${BACULA_GROUP}
CONFIGURE_ARGS+=	--with-sd-user=${BACULA_SD_USER} --with-sd-group=${BACULA_GROUP}
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-smartalloc
.endif

PTHREAD_OPTS+=	require

BUILD_DEFS=	BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP BACULA_DB

PKG_GROUPS=	${BACULA_GROUP}
PKG_USERS=	${BACULA_DIR_USER}:${BACULA_GROUP}
PKG_USERS+=	${BACULA_SD_USER}:${BACULA_GROUP}

BACULA_DB=	sqlite
PLIST_SUBST+=	BACULA_DB=${BACULA_DB}

EXAMPLESDIR=	${PREFIX}/share/examples/bacula
CONF_FILES=	${EXAMPLESDIR}/bacula-dir.conf ${PKG_SYSCONFDIR}/bacula-dir.conf
CONF_FILES+=	${EXAMPLESDIR}/bacula-fd.conf ${PKG_SYSCONFDIR}/bacula-fd.conf
CONF_FILES+=	${EXAMPLESDIR}/bacula-sd.conf ${PKG_SYSCONFDIR}/bacula-sd.conf
CONF_FILES+=	${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf

RCD_SCRIPTS=	bacula bacula-dir bacula-sd bacula-fd

pre-install:
	${MKDIR} ${EXAMPLESDIR}

.if ${BACULA_DB} == "sqlite"
.  include "../../databases/sqlite/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
