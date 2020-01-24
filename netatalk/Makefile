# $NetBSD: Makefile,v 1.7 2015/06/08 17:38:55 fhajny Exp $

DISTNAME=	netatalk-3.1.7
PKGREVISION=	1
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2
#PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk appletalk file and print services
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	l:db48:${BDB_TYPE}

PKG_CONFIG=		yes
PKG_SYSCONFSUBDIR=	netatalk
EGDIR=			${PREFIX}/share/examples/netatalk
#CONF_FILES=		${EGDIR}/afp.conf		${PKG_SYSCONFDIR}/afd.conf
CONF_FILES+=		${DESTDIR}${EGDIR}/afp.conf	${PKG_SYSCONFDIR}/afp.conf
CONF_FILES+=		${EGDIR}/extmap.conf		${PKG_SYSCONFDIR}/extmap.conf
#CONF_FILES+=		${EGDIR}/netatalk-dbus.conf	${PKG_SYSCONFDIR}/netatalk-dbus.conf

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--enable-netbsd
CONFIGURE_ARGS+=	--enable-overwrite
CONFIGURE_ARGS+=	--enable-timelord
CONFIGURE_ARGS+=	--enable-ddp
CONFIGURE_ARGS+=	--enable-quota
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-message-dir=${PKG_SYSCONFDIR}/msg
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db
CONFIGURE_ARGS+=	--with-uams-path=${PREFIX}/libexec/netatalk/uams
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libevent-header=${BUILDLINK_PREFIX.libevent}/include
CONFIGURE_ARGS+=	--with-libevent-lib=${BUILDLINK_PREFIX.libevent}/lib
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CFLAGS.SunOS+=	-I/usr/include/kerberosv5/

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

REPLACE_PYTHON+=	contrib/shell_utils/afpstats

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\\(DVIPS=\\)\\(/usr/local/tex\\)\\(/bin\\),\\1${PREFIX}\\3,"

# PLIST_VARS+=		rcd
# .if ${OPSYS} == "NetBSD"
# RCD_SCRIPTS=		afpd atalkd papd timelord cnid_metad
# .  for f in ${RCD_SCRIPTS}
# RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
# .  endfor
# PLIST.rcd=		yes
# .endif

PLIST_VARS+=		ad ea
.if ${OPSYS} == "SunOS"
PLIST.ad=		yes
.endif
.if ${OPSYS} == "SunOS" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-6].[0-8]*))
PLIST.ea=		yes
.endif

.include "options.mk"

INSTALLATION_DIRS=	libexec/psffilters etc/netatalk ${EGDIR}

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/pam/netatalk ${DESTDIR}${EGDIR}/netatalk.pam
.endif

.include "../../databases/mysql55-client/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
