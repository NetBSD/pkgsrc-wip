# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:57 tvierling Exp $
#

DISTNAME=		fasta3
PKGNAME=		fasta-3.4
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.virginia.edu/pub/fasta/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://fasta.bioch.virginia.edu/
COMMENT=		FASTA sequence comparison programs

MAKEFILE=		Makefile.NetBSD

WRKSRC=			${WRKDIR}

LICENSE= 		non-commercial-use

post-extract:
	${SED} -e 's:/seqprg/slib/bin:@PREFIX@:' \
	       -e 's:your.host.here:@HOSTNAME@:' \
	        ${WRKSRC}/${MAKEFILE} > ${WRKSRC}/${MAKEFILE}.in

do-configure:
	${SED} < ${WRKSRC}/${MAKEFILE}.in > ${WRKSRC}/${MAKEFILE} \
 		-e 's:@PREFIX@:${PREFIX}:' \
	        -e 's:@HOSTNAME@:fasta.bioch.virginia.edu:'
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fasta
.for DOC in README.versions README Readme.Mac readme.mpi_3.3 readme.pvm_3.3  \
	    readme.v30 readme.v30t7 readme.v31t1 readme.v33t0 readme.w32     \
	    readme.pvm_3.2 readme.pvm_3.4 readme.v30t6 readme.v31t0          \
	    readme.v32t0 readme.v34t0 fasta20.doc fasta3x.doc fasta_func.doc \
	    COPYRIGHT FASTA_LIST
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/fasta
.endfor
	${INSTALL_DATA} ${WRKSRC}/fasta3x.me ${PREFIX}/man/man1
.for MAN in fasta3.1 fastf3.1 fasts3.1 map_db.1 prss3.1 pvcomp.1
	${INSTALL_DATA} ${WRKSRC}/${MAN} ${PREFIX}/man/man1
.endfor
.for PROGRAM in fasta34 fasta34_t fastm34 fastm34_t fasts34 fasts34_t  \
	     fastx34 fastx34_t fasty34 fasty34_t prfx34 prss34         \
	     ssearch34 ssearch34_t tfasta34 tfasta34_t tfasts34        \
	     tfasts34_t tfastx34 tfastx34_t tfasty34 tfasty34_t
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.aa ${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.seq ${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*lib ${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/fastlibs ${PREFIX}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC}/*.mat ${PREFIX}/share/examples/fasta

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

