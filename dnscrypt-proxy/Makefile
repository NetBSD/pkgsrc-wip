# $NetBSD$

DISTNAME=	dnscrypt-proxy-1.7.0
CATEGORIES=	security
MASTER_SITES=	https://download.dnscrypt.org/dnscrypt-proxy/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	http://dnscrypt.org/
COMMENT=	Securing DNS communication using DNSCrypt
LICENSE=	mit


GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

DNSCRYPT_USER?=			dnscrypt
DNSCRYPT_GROUP?=		dnscrypt
PKG_GROUPS+=			${DNSCRYPT_GROUP}
PKG_USERS+=			${DNSCRYPT_USER}:${DNSCRYPT_GROUP}
PKG_GROUPS_VARS+=		DNSCRYPT_GROUP
PKG_USERS_VARS+=		DNSCRYPT_USER
PKG_HOME.${DNSCRYPT_USER}?=	${VARBASE}/chroot/dnscrypt
OWN_DIRS+=			${PKG_HOME.${DNSCRYPT_USER}}
OWN_DIRS_PERMS+=		${PKG_HOME.${DNSCRYPT_USER}} ${DNSCRYPT_USER} ${DNSCRYPT_GROUP} 0700

PKGCONFIG_OVERRIDE+=	src/libevent-modified/libevent_core.pc.in
PKGCONFIG_OVERRIDE+=	src/libevent-modified/libevent.pc.in
PKGCONFIG_OVERRIDE+=	src/libevent-modified/libevent_extra.pc.in
PKGCONFIG_OVERRIDE+=	src/libevent-modified/libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=	src/libevent-modified/libevent_pthreads.pc.in

.include "../../devel/libltdl/convenience.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
