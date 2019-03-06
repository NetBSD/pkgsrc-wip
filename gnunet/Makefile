# $NetBSD$

DISTNAME=		gnunet-0.11.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}
PKGREVISION=		1

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

INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=	--with-gnunetdns=gnunetdns

GNUNET_USER=			gnunet
GNUNET_GROUP=			gnunet
GNUNETDNS_GROUP=		gnunetdns
PKG_GECOS.${GNUNET_USER}=	Gnunet
PKG_HOME.${GNUNET_USER}=	${VARBASE}/chroot/gnunet
BUILD_DEFS+=			VARBASE
PKG_SYSCONFSUBDIR=		gnunet

PKG_GROUPS_VARS+=		GNUNET_GROUP
PKG_GROUPS_VARS+=		GNUNETDNS_GROUP
PKG_USERS_VARS=			GNUNET_USER

RCD_SCRIPTS=			gnunet
RCD_SCRIPT_SRC.gnunet=		${FILESDIR}/gnunet.in
PKG_GROUPS=			${GNUNET_GROUP} ${GNUNETDNS_GROUP}
PKG_USERS=			${GNUNET_USER}:${GNUNET_GROUP}
USER_GROUP=			${GNUNET_USER} ${GNUNET_GROUP}

OWN_DIRS_PERMS+=		${PKG_HOME.${GNUNET_USER}} ${USER_GROUP} 0700

MAKE_DIRS+=			${PKG_SYSCONFDIR}
AUTO_MKDIRS=			YES
CONF_FILES+=			${FILESDIR}/gnunet.conf \
				${PKG_SYSCONFDIR}/gnunet.conf

FILES_SUBST+=			PKG_HOME=${PKG_HOME.${GNUNET_USER}}

SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		post-build
SUBST_MESSAGE.sysconfdir=	Fixing sysconfdir in gnunet.conf
SUBST_FILES.sysconfdir=		${FILESDIR}/gnunet.conf
SUBST_SED.sysconfdir=		-e 's,^DEFAULTCONFIG.*,DEFAULTCONFIG = ${PKG_SYSCONFDIR}/gnunet.conf,g'

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

post-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${WRKSRC}/src/util/gnunet-qr.py ${DESTDIR}${PREFIX}/bin
	# XXX: Will be fixed in 0.11.1, rewritten in C.
	# Technically this is no executable script anymore, as we call
	# call it with the shell script. The warning thrown is harmless.
	# https://gnunet.org/en/#gsoc2019
	${CHMOD} -x ${DESTDIR}${PREFIX}/bin/gnunet-qr.py

.if ${OPSYS} == "Linux"
# Do we need more for bluez?
.include "../../wip/bluez-libs/buildlink3.mk"
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
