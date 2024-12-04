# $NetBSD: Makefile,v 1.23 2020/01/18 21:50:41 jperkin Exp $

DISTNAME=	munge-0.5.16
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

CONFIGURE_ARGS+=	--disable-silent-rules

.include "../../mk/bsd.prefs.mk"

MUNGE_DIR?=		${PREFIX}/var/lib/munge
MUNGE_LOG_DIR?=		${PREFIX}/var/log/munge
MUNGE_RUN_DIR?=		${PREFIX}/var/run/munge
MUNGE_ETC_DIR?=		${PREFIX}/etc/munge

# Daemons should not run as root if they don't need to
# Allow override, e.g. env MUNGE_USER=joe MUNGE_GROUP=staff bmake install
.if defined(UNPRIVILEGED_USER) && ${UNPRIVILEGED_USER} == "root"	# Building as root
MUNGE_USER?=		munge
MUNGE_GROUP?=		${MUNGE_USER}
.else
MUNGE_USER?=		${UNPRIVILEGED_USER}
MUNGE_GROUP?=		${UNPRIVILEGED_GROUP}
.endif

PKG_GROUPS+=		${MUNGE_GROUP}
PKG_USERS+=		${MUNGE_USER}:${MUNGE_GROUP}
PKG_GECOS.munge=	Munge user
PKG_HOME.munge=		${MUNGE_DIR}

OWN_DIRS_PERMS+=	${MUNGE_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_LOG_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_RUN_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNGE_ETC_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700

RCD_SCRIPTS=		munge
PKG_RCD_SCRIPTS=	yes

.if ${OPSYS} == Linux
EGDIR=			${PREFIX}/share/examples/munge
PKG_SYSCONFSUBDIR=	sysconfig
CONF_FILES=		${EGDIR}/systemd.sysconfig ${PKG_SYSCONFDIR}/munge
CONF_FILES+=		${EGDIR}/logrotate.conf ${PREFIX}/etc/logrotate.d/munge

INSTALLATION_DIRS+=	${EGDIR} etc/logrotate.d
CONFIGURE_ARGS+=	--with-sysconfigdir=${PKG_SYSCONFDIR}
AUTO_MKDIRS=		yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/logrotate.d/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/logrotate.conf
	${MV} ${DESTDIR}${PREFIX}/etc/sysconfig/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/systemd.sysconfig
.endif

.if ${OPSYS} == Darwin
SUBST_CLASSES+=		launchd
SUBST_STAGE.launchd=	pre-configure
SUBST_SED.launchd=	-e 's|%%MUNGE_USER%%|${MUNGE_USER}|g'
SUBST_SED.launchd+=	-e 's|%%MUNGE_GROUP%%|${MUNGE_GROUP}|g'
SUBST_FILES.launchd=	${WRKDIR}/org.pkgsrc.munged.plist

# Should not be necessary with AUTO_MKDIRS enabled, but it is
INSTALLATION_DIRS+=	share/munge/Launchd
post-patch:
	${CP} ${FILESDIR}/org.pkgsrc.munged.plist ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/org.pkgsrc.munged.plist \
		${DESTDIR}${PREFIX}/share/munge/Launchd
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
