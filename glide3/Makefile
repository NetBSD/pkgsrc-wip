# $NetBSD: Makefile,v 1.12 2012/09/29 00:10:31 asau Exp $
#

DISTNAME=		Glide_V3-2.60-18
CATEGORIES=		graphics
MASTER_SITES=		http://www.alasir.com/glide/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cesar_catrian@yahoo.com
HOMEPAGE=		http://www.alasir.com/glide/
COMMENT=		Software needed for 3dfx voodoo3 cards

NO_CONFIGURE=		yes

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CFLAGS+=		-O

pre-build:
.if defined(DRI) && ${DRI} == "yes"
	cd ${WRKSRC} ; \
	${LN} -sf linhwc.c.dri glide3x/h3/minihwc/linhwc.c ; \
	${LN} -sf gglide.c.dri glide3x/h3/glide3/src/gglide.c ; \
	${LN} -sf glfb.c.dri glide3x/h3/glide3/src/glfb.c ; \
	${LN} -sf gsst.c.dri glide3x/h3/glide3/src/gsst.c
.else
	cd ${WRKSRC} ; \
	${LN} -sf linhwc.c.save glide3x/h3/minihwc/linhwc.c ; \
	${LN} -sf gglide.c.save glide3x/h3/glide3/src/gglide.c ; \
	${LN} -sf glfb.c.save glide3x/h3/glide3/src/glfb.c ; \
	${LN} -sf gsst.c.save glide3x/h3/glide3/src/gsst.c
.endif

do-build:
	cd ${WRKSRC} ; \
	${MAKE_PROGRAM} OS=`uname` FX_GLIDE_HW=h3 -C glide2x ; \
	${MAKE_PROGRAM} OS=`uname` FX_GLIDE_HW=h3 -C glide3x

INSTALLATION_DIRS=	lib

do-install:
	cd ${WRKSRC}/swlibs/lib ; \
	${INSTALL_DATA} libtexus.so.1.1 ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/glide2x/h3/lib ; \
	${INSTALL_DATA} libglide.so.2.60 ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/glide3x/h3/lib ; \
	${INSTALL_DATA} libglide3.so.3.10 ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/glide2x/h3/include ; \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} glide.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} glidesys.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} glideutl.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} sst1vid.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} gump.h ${DESTDIR}${PREFIX}/include/glide
	cd ${WRKSRC}/swlibs/include ; \
	${INSTALL_DATA} 3dfx.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} linutil.h ${DESTDIR}${PREFIX}/include/glide ; \
	${INSTALL_DATA} texus.h ${DESTDIR}${PREFIX}/include/glide
	cd ${WRKSRC}/glide3x/h3/include ; \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} glide.h ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} glidesys.h ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} glideutl.h ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} sst1vid.h ${DESTDIR}${PREFIX}/include/glide3
	cd ${WRKSRC}/swlibs/include ; \
	${INSTALL_DATA} 3dfx.h ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} linutil.h ${DESTDIR}${PREFIX}/include/glide3 ; \
	${INSTALL_DATA} texus.h ${DESTDIR}${PREFIX}/include/glide3

post-install:
	${LN} -sf libtexus.so.1.1 ${PREFIX}/lib/libtexus.so.1
	${LN} -sf libtexus.so.1.1 ${PREFIX}/lib/libtexus.so
	${LN} -sf libglide.so.2.60 ${PREFIX}/lib/libglide.so.2
	${LN} -sf libglide.so.2.60 ${PREFIX}/lib/libglide.so
	${LN} -sf libglide3.so.3.10 ${PREFIX}/lib/libglide3.so.3
	${LN} -sf libglide3.so.3.10 ${PREFIX}/lib/libglide3.so

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
