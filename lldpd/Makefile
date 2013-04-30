# $NetBSD: Makefile,v 1.2 2013/04/30 08:11:10 bbartlomiej Exp $
#

DISTNAME=	lldpd-0.7.2
CATEGORIES=	net
MASTER_SITES=	http://media.luffy.cx/files/lldpd/

MAINTAINER=	bbartlomiej@gmail.com
HOMEPAGE=	http://media.luffy.cx/files/lldpd/
COMMENT=	ISC-licensed implementation of LLDP for various Unixes
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+= awk
USE_LANGUAGES+= c c++

PKGCONFIG_OVERRIDE+=    libevent/libevent.pc.in
PKGCONFIG_OVERRIDE+=    libevent/libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=    libevent/libevent_pthreads.pc.in
PKGCONFIG_OVERRIDE+=    src/lib/lldpctl.pc.in

CONFIGURE_ARGS+=	--with-privsep-chroot=/nonexistent

LLDPD_USER?=	_lldpd
LLDPD_GROUP?=	_lldpd
PKG_GROUPS=		${LLDPD_GROUP}
PKG_USERS=		${LLDPD_USER}:${LLDPD_GROUP}
PKG_HOME.${LLDPD_USER}=	/nonexistent
PKG_GROUPS_VARS=	LLDPD_GROUP
PKG_USERS_VARS=		LLDPD_USER

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
