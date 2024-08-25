# $NetBSD$

.include	"../../wip/libi2pd/Makefile.common"

GIT_SHA=	ce8d701ecb92be1563681ec9ce98a9e4d02041fd
DISTNAME=	i2pd-${GIT_SHA}
PKGNAME=	i2pd-git-${GIT_SHA}
MASTER_SITES=	-https://github.com/PurpleI2P/i2pd/archive/${GIT_SHA}.tar.gz
WRKSRC=		${WRKDIR}/i2pd-${GIT_SHA}/build

COMMENT=	Full-featured C++ implementation of I2P client

CMAKE_CONFIGURE_ARGS+=	-DWITH_BINARY=yes
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBRARY=no

I2PD_USER=	i2pd
I2PD_GROUP=	i2pd

CONFLICTS+=	i2pd-[0-9]*

PKG_USERS=	${I2PD_USER}:${I2PD_GROUP}
PKG_GROUPS=	${I2PD_GROUP}

MAKE_DIRS+=	${PREFIX}/etc/i2pd
MAKE_DIRS+=	${VARBASE}/db/i2pd
MAKE_DIRS+=	${VARBASE}/log/i2pd
MAKE_DIRS+=	${VARBASE}/run/i2pd

MAKE_DIRS_PERMS+=	${VARBASE}/db/i2pd \
					${I2PD_USER} ${I2PD_GROUP} 0755
MAKE_DIRS_PERMS+=	${VARBASE}/log/i2pd \
					${I2PD_USER} ${I2PD_GROUP} 0755
MAKE_DIRS_PERMS+=	${VARBASE}/run/i2pd \
					${I2PD_USER} ${I2PD_GROUP} 0755

post-install:
	${INSTALL_DATA} ${DESTDIR}/${PREFIX}/etc/i2pd

.include "../../mk/bsd.pkg.mk"
