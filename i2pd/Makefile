# $NetBSD$
.include	"../../wip/libi2pd/Makefile.common"

PKGNAME=	i2pd-${I2PD_VERSION}
COMMENT=	Full-featured C++ implementation of I2P client

CONFLICTS+=	i2pd-git-*

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE
USE_TOOLS+=	pax

CMAKE_CONFIGURE_ARGS+=	-DWITH_BINARY=yes
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBRARY=no

EGDIR=		share/examples/i2pd

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing hardcoded path for datadir
SUBST_FILES.fix-paths=		${WRKSRC}/libi2pd/FS.cpp
SUBST_SED.fix-paths=		-e 's,/var/lib,${PREFIX}/var,g'

I2PD_USER=		i2pd
I2PD_GROUP=		i2pd
PKG_HOME.${I2PD_USER}=	${PREFIX}/var/i2pd
PKG_USERS=		${I2PD_USER}:${I2PD_GROUP}
PKG_GROUPS=		${I2PD_GROUP}
PKG_GECOS.${I2PD_USER}=	i2pd user

PKG_SYSCONFSUBDIR=	i2pd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKG_SYSCONFBASE}/i2pd
INSTALLATION_DIRS+=	var/i2pd
INSTALLATION_DIRS+=	var/i2pd/certificates

.if ${OPSYS} == "NetBSD" # NetBSD-specific config
CONF_FILES+=	${EGDIR}/i2pd.conf.NetBSD \
		   ${PREFIX}/${PKG_SYSCONFDIR}/i2pd.conf
.else
CONF_FILES+=	${EGDIR}/i2pd.conf \
		   ${PREFIX}/${PKG_SYSCONFDIR}/i2pd.conf
.endif

RCD_SCRIPTS+=		i2pd
RCD_SCRIPT_SRC.i2pd=	${FILESDIR}/i2pd.in

MAKE_DIRS+=	${VARBASE}/log/i2pd
MAKE_DIRS+=	${VARBASE}/run/i2pd

MAKE_DIRS_PERMS+=	${VARBASE}/log/i2pd \
			${I2PD_USER} ${I2PD_GROUP} 0755

MAKE_DIRS_PERMS+=	${VARBASE}/run/i2pd \
			${I2PD_USER} ${I2PD_GROUP} 0700

MAKE_DIRS_PERMS+=	${PREFIX}/var/i2pd \
			${I2PD_USER} ${I2PD_GROUP} 0700

MAKE_DIRS_PERMS+=	${PREFIX}/var/i2pd/certificates \
			${I2PD_USER} ${I2PD_GROUP} 0700

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/i2pd.1 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/

	cd ${WRKSRC}/contrib/certificates && \
		pax -wr * ${DESTDIR}/${PREFIX}/var/i2pd/certificates/

	${INSTALL_DATA} ${WRKSRC}/contrib/tunnels.conf \
		${DESTDIR}/${PREFIX}/${EGDIR}/tunnels.conf

	${INSTALL_DATA} ${WRKSRC}/contrib/i2pd.conf \
		${DESTDIR}/${PREFIX}/${EGDIR}/i2pd.conf

	${INSTALL_DATA} ${FILESDIR}/i2pd.conf.NetBSD \
		${DESTDIR}/${PREFIX}/${EGDIR}/i2pd.conf.NetBSD

.include "../../mk/bsd.pkg.mk"
