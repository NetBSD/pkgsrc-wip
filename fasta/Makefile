# $NetBSD: Makefile,v 1.9 2012/10/15 22:31:09 asau Exp $

DISTNAME=		fasta-36.3.5d
PKGNAME=		fasta-36.3.5.4 # 4 for "d"
CATEGORIES=		biology
MASTER_SITES=		http://faculty.virginia.edu/wrpearson/fasta/fasta36/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://fasta.bioch.virginia.edu/
COMMENT=		FASTA sequence comparison programs
LICENSE=		no-commercial-use

BUILD_DIRS=		src
MAKE_FILE=		../make/Makefile.NetBSD

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC}/src && ../bin/fasta36 -q ../seq/mgstm1.aa ../seq/prot_test.lseg

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fasta
.for f in README.versions README Readme.Mac readme.mpi_3.3 readme.pvm_3.3    \
	    readme.v30 readme.v30t7 readme.v31t1 readme.v33t0 readme.w32     \
	    readme.pvm_3.2 readme.pvm_3.4 readme.v30t6 readme.v31t0          \
	    readme.v32t0 readme.v34t0 fasta20.doc fasta3x.doc fasta_func.doc \
	    COPYRIGHT FASTA_LIST
	${INSTALL_DATA} ${WRKSRC}/${f:Q} ${DESTDIR}${PREFIX}/share/doc/fasta
.endfor
	${INSTALL_DATA} ${WRKSRC}/fasta3x.me ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in fasta3.1 fastf3.1 fasts3.1 map_db.1 prss3.1 pvcomp.1
	${INSTALL_DATA} ${WRKSRC}/${f:Q} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for f in fasta34 fasta34_t fastm34 fastm34_t fasts34 fasts34_t		\
	     fastx34 fastx34_t fasty34 fasty34_t prfx34 prss34		\
	     ssearch34 ssearch34_t tfasta34 tfasta34_t tfasts34		\
	     tfasts34_t tfastx34 tfastx34_t tfasty34 tfasty34_t
	${INSTALL_PROGRAM} ${WRKSRC}/${f:Q} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.aa ${DESTDIR}${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.seq ${DESTDIR}${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*lib ${DESTDIR}${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/fastlibs ${DESTDIR}${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.mat ${DESTDIR}${PREFIX}/share/examples/fasta

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
