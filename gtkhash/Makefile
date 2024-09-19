# $NetBSD$

DISTNAME=	gtkhash-1.1.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/tristanheaven/gtkhash/releases/download/v1.1.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://github.com/tristanheaven/gtkhash/
COMMENT=	GTK+ utility for computing message digests or checksums
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config

CONFIGURE_ARGS+=	--enable-mbedtls
#CONFIGURE_ARGS+=	--enable-mhash		# commented out due to segmentation fault
CONFIGURE_ARGS+=	--enable-nettle
CONFIGURE_ARGS+=	--disable-blake2	# at present, not available in the pkgsrc collection

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
#.include "../../security/mhash/buildlink3.mk"	# commented out due to segmentation fault
.include "../../security/nettle/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
