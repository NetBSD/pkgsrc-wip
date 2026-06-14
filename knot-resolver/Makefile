# $NetBSD$

DISTNAME=	knot-resolver-6.3.0
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://secure.nic.cz/files/knot-resolver/
COMMENT=	Knot (resolver) DNS server
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	cmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

#RCD_SCRIPTS=	knot-resolver

EGDIR=			${PREFIX}/etc/knot-resolver
#PKG_SYSCONFSUBDIR=	knot-resolver

CONF_FILES+=	${EGDIR}/icann-ca.pem  ${PKG_SYSCONFDIR}/icann-ca.pem
CONF_FILES+=	${EGDIR}/root.hints ${PKG_SYSCONFDIR}/knot-resolver/root.hints
CONF_FILES+=	${EGDIR}/root.keys ${PKG_SYSCONFDIR}/knot-resolver/root.keys

INSTALLATION_DIRS=	${EGDIR}

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
.include "../../devel/meson/build.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
