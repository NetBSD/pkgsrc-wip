# $NetBSD$
.include	"Makefile.common"

PKGNAME=	libi2pd-${I2PD_VERSION}
COMMENT=	i2pd library

CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBRARY=yes
CMAKE_CONFIGURE_ARGS+=	-DWITH_BINARY=no

.include "../../mk/bsd.pkg.mk"
