# $NetBSD: Makefile,v 1.1.1.1 2011/08/04 11:49:17 hfath Exp $

DISTNAME=	netatalk-${DISTVERS}
DISTVERS=	2.0.5
PKGNAME=	netatalk20-${DISTVERS}
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2
PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk v2.0 appletalk file and print services
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=		rc>=1.5:../../shells/rc

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes

BDB_ACCEPTED=		db4 db5
BUILDLINK_TRANSFORM+=	l:db48:${BDB_TYPE}

PKG_SYSCONFSUBDIR=	netatalk
EG_DIR=		${PREFIX}/share/examples/netatalk
CONF_FILES=	${EG_DIR}/AppleVolumes.default \
			${PKG_SYSCONFDIR}/AppleVolumes.default \
		${EG_DIR}/AppleVolumes.system \
			${PKG_SYSCONFDIR}/AppleVolumes.system \
		${EG_DIR}/afpd.conf ${PKG_SYSCONFDIR}/afpd.conf \
		${EG_DIR}/atalkd.conf ${PKG_SYSCONFDIR}/atalkd.conf \
		${EG_DIR}/netatalk.conf ${PKG_SYSCONFDIR}/netatalk.conf \
		${EG_DIR}/papd.conf ${PKG_SYSCONFDIR}/papd.conf

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]* netatalk-[0-9]*

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--enable-netbsd
CONFIGURE_ARGS+=	--enable-overwrite
CONFIGURE_ARGS+=	--enable-timelord
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-message-dir=${PKG_SYSCONFDIR}/msg
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/netatalk
CONFIGURE_ARGS+=	--with-uams-path=${PREFIX}/libexec/netatalk/uams
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

# Netatalk 2.0 has no support for libquota on NetBSD
.if !empty(MACHINE_PLATFORM:MNetBSD-5.99.4[8-9]*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-5.99.[5-9]*)  || \
    !empty(MACHINE_PLATFORM:MNetBSD-[6-9]*)
CONFIGURE_ARGS+=	--disable-quota
.endif

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/psf/etc2ps.sh distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\\(DVIPS=\\)\\(/usr/local/tex\\)\\(/bin\\),\\1${PREFIX}\\3,"

RCD_SCRIPTS=		afpd atalkd papd timelord cnid_metad
.for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
.endfor

SUBST_CLASSES+=		rc
SUBST_FILES.rc=		${WRKSRC}/bin/afile/acleandir.rc
SUBST_SED.rc+=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.rc=		pre-configure

.include "options.mk"

INSTALLATION_DIRS=	libexec/psffilters

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/netatalk.pamd ${DESTDIR}${EG_DIR}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
