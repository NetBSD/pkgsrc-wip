# $NetBSD: Makefile,v 1.9 2012/10/07 16:23:18 asau Exp $

DISTNAME=	svgalib-1.4.3
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.svgalib.org/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.svgalib.org/
COMMENT=	Low level console graphics library


USE_TOOLS+=	gmake
CFLAGS+=	-g -DUSE_LIBC_VM86
MANCOMPRESSED=	yes

BUILD_TARGET=	shared static

#ONLY_FOR_ARCHS=	i386

pre-patch:
	for i in ${WRKSRC}/utils/gtf/*.h; do \
		${TR} -d '\015' < $${i} > $${i}.new; \
		${MV} $${i}.new $${i}; \
	done
	${MKDIR} ${WRKSRC}/include/linux
	for i in ${WRKSRC}/utils/?*textmode ${WRKSRC}/demos/svidtune.c; do \
		${CP} $${i} $${i}.orig; \
		${SED} -e "s,/etc,${PREFIX}/etc,g" < $${i}.orig > $${i}; \
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/linux
	cd ${WRKSRC}/include/linux && \
		${INSTALL_DATA} keyboard.h kd.h ${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
