# $NetBSD: Makefile,v 1.11 2005/04/11 21:10:06 tvierling Exp $
#

DISTNAME=		bacula-1.34.6
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Network Backup Solution

USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR?=	bacula
BACULA_PIDDIR?=		${VARBASE}/run
BACULA_WORKINGDIR?=	${VARBASE}/spool/bacula
BACULA_GROUP?=		bacula
BACULA_DIR_USER?=	bacula-dir
BACULA_SD_USER?=	bacula-sd
BACULA_DB?=		sqlite

.include "../../mk/bsd.prefs.mk"

OWN_DIRS_PERMS=		${BACULA_PIDDIR} root ${BACULA_GROUP} 770
OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} root ${BACULA_GROUP} 770

FILES_SUBST+=		BACULA_ETCDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=		BACULA_PIDDIR=${BACULA_PIDDIR}
FILES_SUBST+=		BACULA_GROUP=${BACULA_GROUP}
FILES_SUBST+=		BACULA_DIR_USER=${BACULA_DIR_USER}
FILES_SUBST+=		BACULA_SD_USER=${BACULA_SD_USER}

CONFIGURE_ARGS+=	--with-sbin-perm=0755
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/libexec/bacula
CONFIGURE_ARGS+=	--with-working-dir=${BACULA_WORKINGDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${BACULA_PIDDIR}
CONFIGURE_ARGS+=	--with-readline=${PREFIX}/include/readline
CONFIGURE_ARGS+=	--with-dir-user=${BACULA_DIR_USER}	\
			--with-dir-group=${BACULA_GROUP}
CONFIGURE_ARGS+=	--with-sd-user=${BACULA_SD_USER}	\
			--with-sd-group=${BACULA_GROUP}
.if ${BACULA_DB} == "sqlite"
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
.endif
.if defined(BACULA_STATIC) && ${BACULA_STATIC} == "YES"
CONFIGURE_ARGS+=	--enable-static-tools --enable-static-fd --enable-static-sd
CONFIGURE_ARGS+=	--enable-static-dir --enable-static-cons
PLIST_SUBST+=		BACULA_STATIC=""
.else
PLIST_SUBST+=		BACULA_STATIC="@comment "
.endif

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-smartalloc
.endif

PTHREAD_OPTS+=	require

BUILD_DEFS=	BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP BACULA_DB
BUILD_DEFS+=	BACULA_ETCDIR BACULA_PIDDIR

PKG_GROUPS=	${BACULA_GROUP}
PKG_USERS=	${BACULA_DIR_USER}:${BACULA_GROUP}
PKG_USERS+=	${BACULA_SD_USER}:${BACULA_GROUP}

PLIST_SUBST+=	BACULA_DB=${BACULA_DB}

EXAMPLESDIR=	${PREFIX}/share/examples/bacula
CONF_FILES=	${EXAMPLESDIR}/bacula-dir.conf	\
		${PKG_SYSCONFDIR}/bacula-dir.conf
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
.include "../../mk/bsd.pkg.mk"
