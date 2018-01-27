# $NetBSD$

DISTNAME=	co031219
PKGNAME=	concorde-20031219
CATEGORIES=	parallel
MASTER_SITES=	http://www.math.uwaterloo.ca/tsp/concorde/downloads/codes/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uwaterloo.ca/tsp/concorde/
COMMENT=	Combinatorial Optimization package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	nawk-[0-9]*:../../lang/nawk

WRKSRC=		${WRKDIR}/concorde

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-pthreads

REPLACE_AWK+=	TINY/randtsp.awk

ALL_TARGET=	everything

BINFILES=	CUT/mincut FMATCH/fmatch LINKERN/linkern \
		 TINY/tinytsp TOOLS/edg2len TOOLS/edgunion TOOLS/fconvert \
		TOOLS/killgrun TOOLS/prob2tsp TOOLS/showres TOOLS/tourchk \
		TOOLS/tourlen TSP/bosstell TSP/concorde TSP/cutserv \
		TSP/poolcat TSP/probserv TSP/test_tsp VERIFY/verify
		
INCFILES=	bigguy.h combs.h config.h consec1.h cut.h cuttree.h \
		delaunay.h edgegen.h fmatch.h heldkarp.h kdtree.h \
		linkern.h localcut.h lp.h machdefs.h macrorus.h mlinkern.h \
		necklace.h pq.h pqsets.h tinytsp.h \
		tsp.h util.h verify.h


INSTALLATION_DIRS=	bin/concorde include/concorde lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/concorde.a \
		${DESTDIR}${PREFIX}/lib/libconcorde.a
	${INSTALL_DATA} ${WRKSRC}/concorde.h \
		${DESTDIR}${PREFIX}/include/concorde.h
	${INSTALL_SCRIPT} ${WRKSRC}/TINY/randtsp.awk \
		${DESTDIR}${PREFIX}/bin/concorde
	for f in ${INCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/INCLUDE/$$f ${DESTDIR}${PREFIX}/include/concorde; \
	done
#	for f in ${BINFILES} ; do	\
#		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin/concorde; \
#	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
