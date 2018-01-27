# $NetBSD: Makefile,v 1.2 2012/12/13 18:20:29 ftigeot Exp $

DISTNAME=	nss-pam-ldapd-0.9.7
CATEGORIES=	databases
MASTER_SITES=	http://arthurdejong.org/nss-pam-ldapd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/nss-pam-ldapd/
COMMENT=	LDAP client for nsswitch
LICENSE=	gnu-lgpl-v2

NSLCD_USER?=		nslcd
NSLCD_GROUP?=		nslcd

PKG_USERS=		${NSLCD_USER}:${NSLCD_GROUP}
PKG_GROUPS=		${NSLCD_GROUP}
PKG_USERS_VARS+=	NSLCD_USER
PKG_GROUPS_VARS+=	NSLCD_GROUP

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/nslcd.conf
CONFIGURE_ARGS+=	--with-nslcd-pidfile=${NSLCD_PIDFILE}
CONFIGURE_ARGS+=	--with-nslcd-socket=${NSLCD_SOCKET}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-nss-ldap-soname=${NSS_LDAP_SONAME}
CONFIGURE_ARGS+=	--with-pam-seclib-dir=${PREFIX}/lib/security
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--with-nss-flavour=freebsd
.endif

REPLACE_PYTHON+=	utils/chsh.py
REPLACE_PYTHON+=	utils/getent.py

# Don't stip the .so objects, they will then be useless
# e.g. because nss_module_register can't be looked up
INSTALL_UNSTRIPPED=	yes

FILES_SUBST+=		PIDFILE=${NSLCD_PIDFILE}

RCD_SCRIPTS+=		nslcd

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
VARDIR=			${VARBASE}/run/nslcd
CONF_FILES=		${EGDIR}/nslcd.conf ${PKG_SYSCONFDIR}/nslcd.conf

NSLCD_PIDFILE?=		${VARDIR}/nslcd.pid
NSLCD_SOCKET?=		${VARDIR}/socket
BUILD_DEFS+=		VARBASE NSLCD_PIDFILE NSLCD_SOCKET

INSTALL_MAKE_FLAGS+=	NSLCD_CONF_PATH=${PKG_SYSCONFDIR}/nslcd.conf

# Install FreeBSD's nss_compat.c and later patch it
pre-patch:
	${CP} ${FILESDIR}/nss_compat.c ${WRKSRC}/compat

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${CHMOD} 0644 ${DESTDIR}${EGDIR}/nslcd.conf

.if ${OPSYS} == "NetBSD"
# Otherwise PAM_EXTERN ends up "static" and -O2 optimizes everything away
CFLAGS+=		-DNO_STATIC_MODULES

INSTALL_TEMPLATES=	INSTALL.nss
DEINSTALL_TEMPLATES=	DEINSTALL.nss
.endif

# NSS_LDAP_SONAME is used by both the NSS client and the server(!)
.if ${OPSYS} == "NetBSD"
NSS_LDAP_SONAME=	nss_ldap.so.0
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "SunOS"
NSS_LDAP_SONAME=	nss_ldap.so.1
.else
NSS_LDAP_SONAME=	libnss_ldap.so.2
.endif

PLIST_SUBST+=		NSS_LDAP_SONAME=${NSS_LDAP_SONAME:Q}

# PAM_LDAP_SONAME is used only by the PAM client, but define it here for consistency
.if ${OPSYS} == "SunOS"
PAM_LDAP_SONAME=	pam_ldap.so.1
.else
PAM_LDAP_SONAME=	pam_ldap.so
.endif

PLIST_SUBST+=		PAM_LDAP_SONAME=${PAM_LDAP_SONAME:Q}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing config file path
SUBST_FILES.fix-paths=		man/*.[0-9] man/*.[0-9].xml
SUBST_SED.fix-paths=		-e 's|/etc/nslcd.conf|${PKG_SYSCONFDIR}/nslcd.conf|g'

# Thread Local Storage seems not to work on NetBSD-4
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-4].*-*)
SUBST_CLASSES+=			disable-tls
SUBST_STAGE.disable-tls=	post-configure
SUBST_MESSAGE.disable-tls=	disabling TLS
SUBST_FILES.disable-tls=	config.h
SUBST_SED.disable-tls=		-e 's|/\* \#undef __thread \*/|\#define __thread /\*\*/|'
.endif

SUBST_CLASSES+=		usergroup
SUBST_STAGE.usergroup=	post-patch
SUBST_FILES.usergroup=	nslcd.conf
SUBST_SED.usergroup=	-e 's/^uid nslcd/uid ${NSLCD_USER}/'
SUBST_SED.usergroup+=	-e 's/^gid nslcd/gid ${NSLCD_GROUP}/'

.include "../../lang/python/application.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
