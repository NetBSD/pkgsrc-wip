# $NetBSD$

DISTNAME=	freebayes-2018.03.23
CATEGORIES=	biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	weinertw@uwm.edu
HOMEPAGE=	https://github.com/ekg/freebayes
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping
LICENSE=	mit

EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CFLAGS+=	-msse2
CXXFLAGS+=	-std=c++11

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Linux
MAKE_FLAGS=	EXTRALIBS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
.else
MAKE_FLAGS+=	EXTRALIBS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
.endif

.if ${MACHINE_ARCH} == i386
CFLAGS+=	-msse2
.endif

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
