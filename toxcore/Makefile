# $NetBSD$

DISTNAME=	c-toxcore-0.1.11
PKGNAME=	toxcore-0.1.11
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=TokTok/}
GITHUB_RELEASE=	v0.1.11

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://tox.chat/
COMMENT=	Tox protocol library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
#USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	libtoxav.pc.in
PKGCONFIG_OVERRIDE+=	libtoxcore.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/toxdns.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/libtoxcore.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/libtoxav.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/toxav.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/toxcore.pc.in
PKGCONFIG_OVERRIDE+=	other/pkgconfig/toxencryptsave.pc.in

.include "../../security/libsodium/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
