# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 17:59:14 daprice Exp $
#

DISTNAME=		ncbi
PKG_VER=		20040505
PKGNAME=		ncbi-bin-${PKG_VER}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/20040505/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox
COMMENT=		Portable, modular software for molecular biology

WRKSRC=			${WRKDIR}/ncbi
DIST_SUBDIR=		${PKGNAME}
USE_BUILDLINK3=         yes
USE_X11=		yes

MAKE_ENV+=		PREFIX=${PREFIX}

do-build:
	cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} ${CSH} ncbi/make/makedis.csh

do-install:
	@${ECHO} "Installing NCBI toolkit"
	@${ECHO} "Installing docs"
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ncbi
.for DOC in FAQ.txt access.txt \
	    asn2gb.txt asn2gph.txt \
	    blast.txt blastclust.txt blastdb.txt blastftp.txt \
	    fastacmd.txt formatdb.txt \
	    impala.txt \
	    megablast.txt \
	    ncbixml.txt netblast.txt \
	    rpsblast.txt \
	    tbl2asn.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/${DOC}  ${PREFIX}/share/doc/ncbi
.endfor
	@${ECHO} "Installing programs"
.for PROGRAM in asn2ff asn2gb asn2xml asndhuff asntool blastall blastcl3 blastclust blastpgp cdscan checksub copymat dosimple entrcmd errhdr fa2htgs fastacmd findspl fmerge formatdb getfeat getmesh getpub getseq gil2bin idfetch impala indexpub makemat makeset megablast ncbisort rpsblast seedtop seqtest tbl2asn vecscreen
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
