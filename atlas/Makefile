# $NetBSD: Makefile,v 1.12 2013/09/14 23:46:50 asau Exp $

DISTNAME=	atlas3.10.2
PKGNAME=	${DISTNAME:C/atlas/atlas-/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=math-atlas/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://math-atlas.sourceforge.net/
COMMENT=	Automatically Tuned Linear Algebra Software
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ATLAS
HAS_CONFIGURE=	yes

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c fortran77
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

ATLAS_CPUBITS=			32
.for p in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${p}}
ATLAS_CPUBITS=			64
.  endif
.endfor

CONFIGURE_DIRS=		obj
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--incdir=${DESTDIR}${PREFIX}/include
CONFIGURE_ARGS+=	--libdir=${DESTDIR}${PREFIX}/lib
CONFIGURE_ARGS+=	-b ${ATLAS_CPUBITS}
CONFIGURE_ARGS+=	-Ss flapack ${PREFIX}/lib/liblapack.a

# atlas requires distfiles from lapack
#.include "../../math/lapack/Makefile.version"
#CONFIGURE_ARGS+=	--with-netlib-lapack-tarfile=${DISTDIR}/${LAPACK_NAME}-${LAPACK_VERSION}${LAPACK_SUFX}
CONFIGURE_ARGS+=	--with-netlib-lapack-tarfile=${DISTDIR}/lapack-3.5.0.tgz

TEST_TARGET=	check
BUILD_TARGET=	build shared ptshared

pre-configure:
	${RUN} cd ${WRKSRC}; mkdir ${CONFIGURE_DIRS}

# Ignore messages from ./xprobe_comp like:
#   cd /tmp/pkgsrc-tmp/wip/atlas/work/ATLAS/obj ; ./xprobe_comp -v 0 -o atlconf.txt -O 13 -A 27 -Si nof77 0 -V 480   -b 32 -d b /tmp/pkgsrc-tmp/wip/atlas/work/ATLAS/obj > config1.out
#   find:: not found
# Atlas iterates over all paths from PATH and executes find(1)

.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
