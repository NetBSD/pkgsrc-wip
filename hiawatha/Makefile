# $NetBSD$

DISTNAME=	hiawatha-11.5
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hiawatha-webserver.org/files/
COMMENT=	Advanced and secure webserver for Unix
LICENSE=	gnu-gpl-v2


USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DUSE_SHARED_MBEDTLS_LIBRARY=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_STATIC_MBEDTLS_LIBRARY=ON
CMAKE_CONFIGURE_ARGS+=	-DWEBROOT_DIR="${PREFIX}/var/hiawatha"
CMAKE_CONFIGURE_ARGS+=	-DWORK_DIR="${PREFIX}/var/db/hiawatha"
CMAKE_CONFIGURE_ARGS+=	-DCONFIG_DIR="${PREFIX}/etc/hiawatha"
CMAKE_CONFIGURE_ARGS+=	-DLOG_DIR="${PREFIX}/var/log/hiawatha"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR="${PREFIX}/man"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_XSLT=ON
CMAKE_CONFIGURE_ARGS+=	-DPID_DIR="${PREFIX}/var/run"

.include "options.mk"

LDFLAGS+=	"-L${WRKDIR}/hiawatha/mbedtls/library"

REPLACE_PHP+=	extra/letsencrypt/lefh.in

# TODO: having issues requiring PHP
CHECK_INTERPRETER_SKIP+=	sbin/lefh

EGDIR=	${PREFIX}/share/examples/hiawatha
ETCDIR=	${PKG_SYSCONFDIR}/hiawatha
FILESDIR=	${PKGDIR}/../../wip/hiawatha/files

CONF_FILES+=	${EGDIR}/error.xslt ${ETCDIR}/error.xslt
CONF_FILES+=	${EGDIR}/hiawatha.conf ${ETCDIR}/hiawatha.conf
CONF_FILES+=	${EGDIR}/index.xslt ${ETCDIR}/index.xslt
CONF_FILES+=	${EGDIR}/mimetype.conf ${ETCDIR}/mimetype.conf
CONF_FILES+=	${EGDIR}/cgi-wrapper.conf ${ETCDIR}/cgi-wrapper.conf

INSTALLATION_DIRS+=	${EGDIR} ${RCDIR}

RCD_SCRIPTS=	hiawatha

HIAWATHA_USER?=		hiawatha
HIAWATHA_GROUP?=	hiawatha

PKG_USERS_VARS+=	HIAWATHA_USER
PKG_GROUPS_VARS+=	HIAWATHA_GROUP
PKG_GROUPS=		${HIAWATHA_GROUP}
PKG_USERS=		${HIAWATHA_USER}:${HIAWATHA_GROUP}

PKG_GECOS.${HIAWATHA_USER}=	HIAWATHA web server user
PKG_HOME.${HIAWATHA_USER}=	${HIAWATHA_DATADIR}
PKG_SHELL.${HIAWATHA_USER}=	${NOLOGIN}

post-install:
	${MV} ${DESTDIR}${ETCDIR}/hiawatha.conf ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${ETCDIR}/mimetype.conf ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${ETCDIR}/cgi-wrapper.conf ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${ETCDIR}/error.xslt ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${ETCDIR}/index.xslt ${DESTDIR}${EGDIR}

.include "../../devel/cmake/build.mk"
.include "../../lang/php/replace.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
