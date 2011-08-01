# $NetBSD: Makefile,v 1.6 2011/08/01 14:55:22 hfath Exp $

DISTNAME=	netatalk-2.2.0
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2
PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk appletalk file and print services
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	l:db48:${BDB_TYPE}

PKG_SYSCONFSUBDIR=	netatalk
EGDIR=		${PREFIX}/share/examples/netatalk
CONF_FILES=	${EGDIR}/AppleVolumes.default ${PKG_SYSCONFDIR}/AppleVolumes.default
CONF_FILES+=	${EGDIR}/AppleVolumes.system ${PKG_SYSCONFDIR}/AppleVolumes.system
CONF_FILES+=	${EGDIR}/afpd.conf ${PKG_SYSCONFDIR}/afpd.conf
CONF_FILES+=	${EGDIR}/netatalk.conf ${PKG_SYSCONFDIR}/netatalk.conf

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--enable-netbsd
CONFIGURE_ARGS+=	--enable-overwrite
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-message-dir=${PKG_SYSCONFDIR}/msg
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/netatalk
CONFIGURE_ARGS+=	--with-uams-path=${PREFIX}/libexec/netatalk/uams
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

# Workaround for Netatalk bug #3380785
CONFIGURE_ARGS+=	--without-ldap

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

RCD_SCRIPTS=		afpd cnid_metad

.include "options.mk"

.if !empty(PKG_OPTIONS:Mddp)
SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths in pap scripts.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/psf/etc2ps.sh distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\\(DVIPS=\\)\\(/usr/local/tex\\)\\(/bin\\),\\1${PREFIX}\\3,"

SUBST_CLASSES+=		deps
SUBST_MESSAGE.deps=	Adding atalkd dependency to afpd rc.d script.
SUBST_STAGE.deps=	pre-configure
SUBST_FILES.deps=	distrib/initscripts/rc.afpd.netbsd.tmpl
SUBST_SED.deps=		-e 's,^\(\# REQUIRE:\),\1 atalkd,'

CONF_FILES+=		${EGDIR}/atalkd.conf ${PKG_SYSCONFDIR}/atalkd.conf
CONF_FILES+=		${EGDIR}/papd.conf ${PKG_SYSCONFDIR}/papd.conf
RCD_SCRIPTS+=		atalkd papd timelord
INSTALLATION_DIRS=	libexec/psffilters
.endif

.for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
.endfor

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/pam/netatalk.pam ${DESTDIR}${EGDIR}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
