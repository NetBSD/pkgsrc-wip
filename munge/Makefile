# $NetBSD: Makefile,v 1.23 2020/01/18 21:50:41 jperkin Exp $

DISTNAME=	munge-0.5.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dun/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INSTALLATION_DIRS+=	lib/pkgconfig

MUNGE_DIR?=		${PREFIX}/var/lib/munge
MUNGE_LOG_DIR?=		${PREFIX}/var/log/munge
MUNGE_RUN_DIR?=		${PREFIX}/var/run/munge
MUNGE_ETC_DIR?=		${PREFIX}/etc/munge
MUNGE_USER=		munge
MUNGE_GROUP=		${MUNGE_USER}

PKG_GROUPS+=		${MUNGE_GROUP}
PKG_USERS+=		${MUNGE_USER}:${MUNGE_GROUP}
PKG_GECOS.munge=	Munge user
PKG_HOME.munge=		${MUNGE_DIR}

OWN_DIRS_PERMS+=	${MUNGE_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_LOG_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_RUN_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNGE_ETC_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700

RCD_SCRIPTS+=	munge

# SUBST_CLASSES+=		init
# SUBST_STAGE.init=	pre-configure
# SUBST_FILES.init=	src/etc/munge.sysvinit.init.in
# SUBST_SED.init=		-e 's|USER="munge"|USER="daemon"|g'
# SUBST_SED.init+=	-e 's|GROUP="munge"|GROUP="daemon"|g'

# SUBST_CLASSES+=		systemd
# SUBST_STAGE.systemd=	pre-configure
# SUBST_FILES.systemd=	src/etc/munge.systemd.service.in
# SUBST_SED.systemd=	-e 's|User=munge|User=daemon|g'
# SUBST_SED.systemd+=	-e 's|Group=munge|Group=daemon|g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Linux
EGDIR=			${PREFIX}/share/examples/munge
# Doesn't work on Lubuntu 23.  Using CONFIGURE_ARGS for now.
# PKG_SYSCONFSUBDIR=	sysconfig
CONF_FILES=		${EGDIR}/systemd.sysconfig ${PKG_SYSCONFDIR}/munge
CONF_FILES+=		${EGDIR}/logrotate.conf ${PREFIX}/etc/logrotate.d/munge

INSTALLATION_DIRS+=	${EGDIR} etc/logrotate.d
CONFIGURE_ARGS+=	--with-sysconfigdir=${PREFIX}/etc/sysconfig

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/logrotate.d/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/logrotate.conf
	${MV} ${DESTDIR}${PREFIX}/etc/sysconfig/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/systemd.sysconfig
.endif

.if ${OPSYS} == Darwin
post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/munge/Launchd
	${INSTALL_DATA} ${FILESDIR}/*.plist \
		${DESTDIR}${PREFIX}/share/munge/Launchd
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
