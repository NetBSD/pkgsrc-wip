# $NetBSD: Makefile,v 1.144 2018/11/10 21:14:53 maya Exp $

DISTNAME=	tiff-4.0.10
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/libtiff/
ABI?=		32
PKGNAME=	compat${ABI}_tiff-4.0.10

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simplesystems.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files
LICENSE=	mit

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/emul/netbsd32/
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--without-x # just in case detects gl to build tiffgt

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

PKGCONFIG_OVERRIDE=	libtiff-4.pc.in

TEST_TARGET=		check

post-install:
	cd ${DESTDIR}/${PREFIX}/emul/netbsd32/man/man3 && for file in *.3tiff; do\
		target=`${ECHO} $$file | sed "s/3tiff/3/"`; \
		${MV} $$file $$target; \
	done

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
# XXX for liblzma; there are more potential suppliers
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
