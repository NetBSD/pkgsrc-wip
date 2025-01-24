# $NetBSD$

DISTNAME=	knot-resolver-5.7.4
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://secure.nic.cz/files/knot-resolver/
COMMENT=	Knot (resolver) DNS server
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

CMAKE_ARGS+=		-DINSTALL_BINDIR="bin"
CMAKE_ARGS+=		-DINSTALL_INFODIR="${PKGINFODIR}"
CMAKE_ARGS+=		-DINSTALL_LIBDIR="${PKGLIBDIR}"
CMAKE_ARGS+=		-DINSTALL_MANDIR="${PKGMANDIR}"
CMAKE_ARGS+=		-DCMAKE_INSTALL_SYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=		-DINSTALL_SBINDIR="sbin"
CMAKE_ARGS+=		-DINSTALL_SCRIPTDIR="bin"

MESON_ARGS+=		-Dinstall_kresd_conf=enabled

PKG_SYSCONFVAR=		knot-resolver

MAKE_DIRS+=             ${LOCALBASE}/var/cache/knot-resovler

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=	yes
USE_TOOLS+=	cmake pkg-config

RCD_SCRIPTS=	kresd

.include "../../net/knot/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../mk/tools/pkg-config.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
