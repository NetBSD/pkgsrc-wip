# $NetBSD$

DISTNAME=	hiawatha-11.5
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hiawatha-webserver.org/files/
COMMENT=	Advanced and secure webserver for Unix
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes

CMAKE_ARGS+=	-DUSE_SHARED_MBEDTLS_LIBRARY=OFF
CMAKE_ARGS+=	-DUSE_STATIC_MBEDTLS_LIBRARY=ON
CMAKE_ARGS+=	-DWEBROOT_DIR="${PREFIX}/var/hiawatha"
CMAKE_ARGS+=	-DWORK_DIR="${PREFIX}/var/db/hiawatha"
CMAKE_ARGS+=	-DCONFIG_DIR="${PREFIX}/etc/hiawatha"
CMAKE_ARGS+=	-DLOG_DIR="${PREFIX}/var/log/hiawatha"
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR="${PREFIX}/man"
CMAKE_ARGS+=	-DENABLE_XSLT=ON
CMAKE_ARGS+=	-DPID_DIR="${PREFIX}/var/run"

LDFLAGS+=	"-L${WRKDIR}/hiawatha/mbedtls/library"

REPLACE_PHP+=	extra/letsencrypt/lefh.in

# TODO: having issues requiring PHP
CHECK_INTERPRETER_SKIP+=	sbin/lefh

.include "../../lang/php/replace.mk"
.include "../../devel/cmake/build.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
