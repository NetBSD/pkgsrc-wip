# $NetBSD$

DISTNAME=		gnunet-0.11.5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://gnunet.org/
COMMENT=		Framework for secure P2P networking
LICENSE=		gnu-agpl-v3

USE_TOOLS+=		msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=	--with-gnunetdns=gnunetdns

BUILD_DEFS+=			VARBASE

GNUNET_DIR?=			${VARBASE}/chroot/gnunet
GNUNET_LOG_DIR?=		${VARBASE}/log/gnunet
GNUNET_USER=			gnunet
GNUNET_GROUP=			gnunet
GNUNETDNS_GROUP=		gnunetdns
PKG_SYSCONFSUBDIR=		gnunet

PKG_GROUPS+=			${GNUNET_GROUP}
PKG_GROUPS+=			${GNUNETDNS_GROUP}
PKG_USERS+=			${GNUNET_USER}:${GNUNET_GROUP}
PKG_GECOS.gnunet=		GNUnet System user
PKG_HOME.gnunet=		${GNUNET_DIR}

RCD_SCRIPTS=			gnunet
RCD_SCRIPT_SRC.gnunet=		${FILESDIR}/gnunet.in

OWN_DIRS_PERMS+=		${GNUNET_DIR} ${GNUNET_USER} ${GNUNET_GROUP} 0700
OWN_DIRS_PERMS+=		${GNUNET_LOG_DIR} ${GNUNET_USER} ${GNUNET_GROUP} 0755
OWN_DIRS_PERMS+=		${GNUNET_DIR}/data ${GNUNET_USER} ${GNUNET_GROUP} 0700

MAKE_DIRS+=			${PKG_SYSCONFDIR}
MAKE_DIRS+=			${GNUNET_LOG_DIR}
MAKE_DIRS+=			${GNUNET_DIR}/data
AUTO_MKDIRS=			YES
CONF_FILES+=			${FILESDIR}/gnunet.conf \
				${PKG_SYSCONFDIR}/gnunet.conf

FILES_SUBST+=			PKG_HOME=${GNUNET_DIR}

SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		post-build
SUBST_MESSAGE.sysconfdir=	Fixing paths in gnunet.conf
SUBST_FILES.sysconfdir=		${FILESDIR}/gnunet.conf
SUBST_SED.sysconfdir+=		-e 's,^DEFAULTCONFIG.*,DEFAULTCONFIG = ${PKG_SYSCONFDIR}/gnunet.conf,g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_DATA_HOME.*,GNUNET_DATA_HOME = ${GNUNET_DIR}/data,g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_RUNTIME_DIR.*,GNUNET_RUNTIME_DIR = ${GNUNET_DIR},g'
SUBST_SED.sysconfdir+=		-e 's,^GNUNET_HOME.*,GNUNET_HOME = ${GNUNET_DIR},g'

# All helpers have to be suid. fs helper must not be suid.
# Not all of these files may be available.
# This is only necessary when the installation was not run
# as root. Run it to ensure that no manual intervention is
# necessary.
# ${CHMOD} root:${GNUNETDNS_GROUP} ${DESTDIR}${PREFIX}/lib/gnunet/libexec/gnunet-helper-dns
# ${CHMOD} ${GNUNET_USER}:${GNUNETDNS_GROUP} ${DESTDIR}${PREFIX}/lib/gnunet/libexec/gnunet-service-dns
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-dns ${REAL_ROOT_USER} ${GNUNETDNS_GROUP} 4750
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-service-dns ${GNUNET_USER} ${GNUNETDNS_GROUP} 2750
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-testbed ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-exit ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-nat-client ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-nat-server ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-transport-bluetooth ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-transport-wlan ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/lib/gnunet/libexec/gnunet-helper-vpn ${SETUID_ROOT_PERMS}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../wip/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
