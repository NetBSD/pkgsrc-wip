# $NetBSD: Makefile,v 1.1.1.1 2003/07/29 14:17:51 cubidou Exp $

MODNAME=		exif
CATEGORIES+=		graphics
COMMENT=		PHP4 extension to manipulate EXIF files

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-exif=shared,${BUILDLINK_PREFIX.exif}

.include "../../graphics/libexif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
