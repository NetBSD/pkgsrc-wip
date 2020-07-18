# $NetBSD$

DISTNAME=		gnunet-0.13.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://gnunet.org/
COMMENT=		Framework for secure P2P networking
LICENSE=		gnu-agpl-v3

USE_TOOLS+=		msgfmt pkg-config # gmake
USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=	--with-gnunetdns=gnunetdns

GNUNET_DIR=		${VARBASE}/chroot/gnunet
GNUNET_LOG_DIR?=	${VARBASE}/log/gnunet
GNUNET_USER=		gnunet
GNUNET_GROUP=		gnunet
GNUNETDNS_GROUP=	gnunetdns
PKG_SYSCONFSUBDIR=	gnunet

PKG_GROUPS+=		${GNUNET_GROUP}
PKG_GROUPS+=		${GNUNETDNS_GROUP}
PKG_USERS+=		${GNUNET_USER}:${GNUNET_GROUP}
PKG_GECOS.gnunet=	GNUnet System user
PKG_HOME.gnunet=	${GNUNET_DIR}

RCD_SCRIPTS=			gnunet gnunetuser
RCD_SCRIPT_SRC.gnunet=		${FILESDIR}/gnunet.in
RCD_SCRIPT_SRC.gnunetuser=	${FILESDIR}/gnunetuser.in

OWN_DIRS_PERMS+=	${PKG_HOME.gnunet} ${GNUNET_USER} ${GNUNET_GROUP} 0700
OWN_DIRS_PERMS+=	${GNUNET_LOG_DIR} ${GNUNET_USER} ${GNUNET_GROUP} 0755
OWN_DIRS_PERMS+=	${GNUNET_DIR}/data ${GNUNET_USER} ${GNUNET_GROUP} 0700

MAKE_DIRS+=		${PKG_SYSCONFDIR}
MAKE_DIRS+=		${GNUNET_DIR}
MAKE_DIRS+=		${GNUNET_LOG_DIR}
MAKE_DIRS+=		${GNUNET_DIR}/data
AUTO_MKDIRS=		YES
CONF_FILES+=		${FILESDIR}/gnunet.conf \
			${PKG_SYSCONFDIR}/gnunet.conf
CONF_FILES+=		${FILESDIR}/gnunet_user.conf \
			${PKG_SYSCONFDIR}/gnunet_user.conf

FILES_SUBST+=		PKG_HOME=${GNUNET_DIR}

# TODO: This should be an .in file, but how.
SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		post-build
SUBST_MESSAGE.sysconfdir=	Fixing paths in gnunet.conf
SUBST_FILES.sysconfdir=		${FILESDIR}/gnunet.conf
SUBST_SED.sysconfdir+=		-e 's,^DEFAULTCONFIG.*,DEFAULTCONFIG = ${PKG_SYSCONFDIR}/gnunet.conf,g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_DATA_HOME.*,GNUNET_DATA_HOME = ${GNUNET_DIR}/data,g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_RUNTIME_DIR.*,GNUNET_RUNTIME_DIR = ${GNUNET_DIR},g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_HOME.*,GNUNET_HOME = ${GNUNET_DIR},g'

# All helpers have to be suid. fs helper must not be suid.
# Some helpers and functionalities are only supported on
# some Operating Systems so far.
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-testbed ${SETUID_ROOT_PERMS}

.if ${OPSYS} == "Linux"
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-dns ${REAL_ROOT_USER} ${GNUNETDNS_GROUP} 4750
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-service-dns ${GNUNET_USER} ${GNUNETDNS_GROUP} 2750
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-exit ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-transport-bluetooth ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-transport-wlan ${SETUID_ROOT_PERMS}
.endif

SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-vpn ${SETUID_ROOT_PERMS}

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD"
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-nat-client ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-nat-server ${SETUID_ROOT_PERMS}
.endif


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
