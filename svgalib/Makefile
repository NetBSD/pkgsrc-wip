# $NetBSD: Makefile,v 1.4 2004/04/12 02:43:56 blef Exp $
# FreeBSD: ports/graphics/svgalib/Makefile,v 1.10 2003/03/07 06:04:12 ade Exp
#

DISTNAME=	svgalib-1.4.3
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.svgalib.org/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.svgalib.org/
COMMENT=	Low level console graphics library

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
CFLAGS+=	-g -DUSE_LIBC_VM86
MANCOMPRESSED=	yes

ALL_TARGET=	shared static

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
