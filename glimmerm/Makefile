# $NetBSD: Makefile,v 1.9 2012/09/29 00:15:13 asau Exp $
#

DISTNAME=		GlimmerM-2.5.1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GlimmerM/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software/glimmerm/
COMMENT=		Gene finder developed specifically for eukaryotes

MAKE_FILE=		makefile
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/GlimmerM

BUILD_DIRS=		sources train

USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sources/glimmerm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_DATA} ${WRKSRC}/train/readme.train ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/train/trainGlimmerM ${DESTDIR}${PREFIX}/share/glimmerm
.for f in mktree build1 falsecomp findsites karlin score scoreATG \
	scoreSTOP updomeasure build-imm build-icm dtscore
	${INSTALL_PROGRAM} ${WRKSRC}/train/${f:Q} ${DESTDIR}${PREFIX}/share/glimmerm
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/train/orf.pm ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/train/formtrain.pm ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/train/filter.pm ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/train/dectree.pm ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_SCRIPT} ${WRKSRC}/train/dectree.no_oblique.pm ${DESTDIR}${PREFIX}/share/glimmerm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/glimmerm
	${INSTALL_DATA} ${WRKSRC}/README.first ${DESTDIR}${PREFIX}/share/doc/glimmerm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/glimmerm
	${CP} -r ${WRKSRC}/trained_dir ${DESTDIR}${PREFIX}/share/examples/glimmerm

.include "../../mk/bsd.pkg.mk"
