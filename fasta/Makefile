# $NetBSD: Makefile,v 1.8 2012/09/28 22:14:13 asau Exp $
#

DISTNAME=		fasta3
PKGNAME=		fasta-3.4
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.virginia.edu/pub/fasta/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://fasta.bioch.virginia.edu/
COMMENT=		FASTA sequence comparison programs
LICENSE=		no-commercial-use

MAKE_FILE=		Makefile.NetBSD

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	${SED} -e 's:/seqprg/slib/bin:@PREFIX@:' \
	       -e 's:your.host.here:@HOSTNAME@:' \
	        ${WRKSRC:Q}/${MAKE_FILE:Q} > ${WRKSRC:Q}/${MAKE_FILE:Q}.in

do-configure:
	${SED} < ${WRKSRC:Q}/${MAKE_FILE:Q}.in > ${WRKSRC:Q}/${MAKE_FILE:Q} \
		-e 's:@PREFIX@:${PREFIX}:' \
	        -e 's:@HOSTNAME@:fasta.bioch.virginia.edu:'
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/doc/fasta
.for f in README.versions README Readme.Mac readme.mpi_3.3 readme.pvm_3.3    \
	    readme.v30 readme.v30t7 readme.v31t1 readme.v33t0 readme.w32     \
	    readme.pvm_3.2 readme.pvm_3.4 readme.v30t6 readme.v31t0          \
	    readme.v32t0 readme.v34t0 fasta20.doc fasta3x.doc fasta_func.doc \
	    COPYRIGHT FASTA_LIST
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${PREFIX:Q}/share/doc/fasta
.endfor
	${INSTALL_DATA} ${WRKSRC:Q}/fasta3x.me ${DESTDIR}${PREFIX:Q}/${PKGMANDIR}/man1
.for f in fasta3.1 fastf3.1 fasts3.1 map_db.1 prss3.1 pvcomp.1
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${PREFIX:Q}/${PKGMANDIR}/man1
.endfor
.for f in fasta34 fasta34_t fastm34 fastm34_t fasts34 fasts34_t		\
	     fastx34 fastx34_t fasty34 fasty34_t prfx34 prss34		\
	     ssearch34 ssearch34_t tfasta34 tfasta34_t tfasts34		\
	     tfasts34_t tfastx34 tfastx34_t tfasty34 tfasty34_t
	${INSTALL_PROGRAM} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${PREFIX:Q}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC:Q}/*.aa ${DESTDIR}${PREFIX:Q}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC:Q}/*.seq ${DESTDIR}${PREFIX:Q}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC:Q}/*lib ${DESTDIR}${PREFIX:Q}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC:Q}/fastlibs ${DESTDIR}${PREFIX:Q}/share/examples/fasta
	${INSTALL_DATA} ${WRKSRC:Q}/*.mat ${DESTDIR}${PREFIX:Q}/share/examples/fasta

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
