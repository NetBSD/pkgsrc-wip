# $NetBSD$
.include	"../../wip/libi2pd/Makefile.common"

PKGNAME=	i2pd-${I2PD_VERSION}

COMMENT=	Full-featured C++ implementation of I2P client

CMAKE_ARGS+=	-DWITH_BINARY=yes
CMAKE_ARGS+=	-DWITH_LIBRARY=no

I2PD_USER=		i2pd
I2PD_GROUP=		i2pd
PKG_GECOS.${I2PD_USER}=	i2pd user

CONFLICTS+= i2pd-git-*

PKG_USERS=	${I2PD_USER}:${I2PD_GROUP}
PKG_GROUPS=	${I2PD_GROUP}

I2PD_SOURCESDIR=${WRKSRC}/..
PKG_SYSCONFSUBDIR=i2pd
I2PD_CONFDIR=${DESTDIR}/${PKG_SYSCONFBASE}/i2pd

MAKE_DIRS+=${VARBASE}/db/i2pd
MAKE_DIRS+=${VARBASE}/log/i2pd
MAKE_DIRS+=${VARBASE}/run/i2pd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/examples/i2pd
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKG_SYSCONFBASE}/i2pd
INSTALLATION_DIRS+=	var/i2pd/

MAKE_DIRS_PERMS+=${I2PD_CONFDIR} \
				 ${I2PD_USER} ${I2PD_GROUP} 0755
MAKE_DIRS_PERMS+=${VARBASE}/db/i2pd \
				 ${I2PD_USER} ${I2PD_GROUP} 0755
MAKE_DIRS_PERMS+=${VARBASE}/log/i2pd \
				 ${I2PD_USER} ${I2PD_GROUP} 0755
MAKE_DIRS_PERMS+=${VARBASE}/run/i2pd \
				 ${I2PD_USER} ${I2PD_GROUP} 0755

post-install:
	${INSTALL_MAN} ${I2PD_SOURCESDIR}/debian/i2pd.1 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${I2PD_SOURCESDIR}/contrib/i2pd.conf \
		${I2PD_CONFDIR}/
	${INSTALL_DATA} ${I2PD_SOURCESDIR}/contrib/tunnels.conf \
		${DESTDIR}/${PREFIX}/share/examples/i2pd/
	cp -Rv ${I2PD_SOURCESDIR}/contrib/certificates \
		${DESTDIR}/${PREFIX}/var/i2pd

.include "../../mk/bsd.pkg.mk"
