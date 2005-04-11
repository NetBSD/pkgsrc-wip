# $NetBSD: Makefile,v 1.2 2005/04/11 21:16:13 tvierling Exp $
#

DISTNAME=		wise2.2.0
PKGNAME=                wise-2.2.0
WRKSRC=			${WRKDIR}/wise2.2.0/src
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/wise2/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.ebi.ac.uk/Wise2
COMMENT=		Tool for Comparing bio polymers like DNA and Protein sequences

MAKEFILE=		makefile
MESSAGE_SUBST+=		PREFIX=${PREFIX}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/BLOSUM30.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/BLOSUM45.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/BLOSUM62.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/BLOSUM80.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/blosum30.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/blosum62.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/cb.tmf ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/codon.table ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gene.stat ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gon120.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gon160.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gon200.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gon250.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/gon350.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/human.gf ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/human.gp ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/human.stats ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/idenity.bla ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/methods ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/pb.gf ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/pombe.gf ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/tm.pri ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/wise.2 ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/wise.per ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/worm.gf ${PREFIX}/share/wise2/wisecfg
	${INSTALL_DATA} ${WRKSRC}/../wisecfg/aa.rnd ${PREFIX}/share/wise2/wisecfg
.for PROGRAM in dba estwise genewise genomewise pswdb dnal estwisedb \
		genewisedb psw
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
