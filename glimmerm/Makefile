# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 21:41:33 daprice Exp $
#

DISTNAME=		GlimmerM-2.5.1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GlimmerM/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software/glimmerm/
COMMENT=		Gene finder developed specifically for eukaryotes

MAKEFILE=		makefile
USE_GNU_TOOLS+=		make

WRKSRC=         	${WRKDIR}/GlimmerM/sources

USE_BUILDLINK3=         yes

post-build:
	cd ${WRKSRC}/../train; ${GMAKE}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glimmerm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/glimmerm
	${INSTALL_DATA} ${WRKSRC}/../train/readme.train ${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/../train/trainGlimmerM ${PREFIX}/share/glimmerm
.for PGM in mktree build1 falsecomp findsites karlin score scoreATG \
	scoreSTOP updomeasure build-imm build-icm dtscore
	${INSTALL_PROGRAM} ${WRKSRC}/../train/${PGM} ${PREFIX}/share/glimmerm
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/../train/orf.pm ${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/../train/formtrain.pm ${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/../train/filter.pm ${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/../train/dectree.pm ${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/../train/dectree.no_oblique.pm ${PREFIX}/share/glimmerm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimmerm
	${INSTALL_DATA} ${WRKSRC}/../README.first ${PREFIX}/share/doc/glimmerm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/glimmerm
	${CP} -r ${WRKSRC}/../trained_dir ${PREFIX}/share/examples/glimmerm

.include "../../mk/bsd.pkg.mk"
