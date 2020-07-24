# $NetBSD$

DISTNAME=	vcflib-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcflib/}
GITHUB_TAG=	7e3d8066a6c6c0f22191a70d050ead23f9c453b3

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/vcflib/vcflib
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

SUBST_CLASSES+=		ldflags
SUBST_FILES.ldflags=	${WRKSRC}/Makefile.external-libs
SUBST_STAGE.ldflags=	post-patch
SUBST_SED.ldflags=	-e "s|LDFLAGS =|LDFLAGS = ${COMPILER_RPATH_FLAG}${PREFIX}/lib|g"

CXXFLAGS+=	-I${PREFIX}/include/smithwaterman \
		-I${PREFIX}/include/multichoose \
		-I${PREFIX}/include/filevercmp \
		-I${PREFIX}/include/fastahack \
		-I${PREFIX}/include/intervaltree \
		-DVERSION='"${PORTVERSION}"'
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_FLAGS=	LIB_PATH+=${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_FILE=	Makefile.external-libs
INSTALL_TARGET=	install-strip

PORTVERSION=	0.0.0.20180208

.include "../../mk/bsd.prefs.mk"

# GCC disables sse2 by default on i386, but it's required for vcflib
.if ${MACHINE_ARCH} == i386
CFLAGS+=	-msse2
.endif

pre-configure:
	${CP} ${FILESDIR}/Makefile.external-libs ${WRKSRC}

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s libvcflib.so.1 libvcflib.so

.include "../../biology/htslib/buildlink3.mk"
.include "../../wip/tabixpp/buildlink3.mk"
.include "../../wip/smithwaterman/buildlink3.mk"
.include "../../wip/fastahack/buildlink3.mk"
.include "../../wip/filevercmp/buildlink3.mk"
.include "../../wip/fsom/buildlink3.mk"
.include "../../wip/multichoose/buildlink3.mk"
.include "../../wip/intervaltree/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
