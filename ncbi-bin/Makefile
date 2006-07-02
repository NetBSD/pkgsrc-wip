# $NetBSD: Makefile,v 1.8 2006/07/02 19:04:35 shattered Exp $
#

DISTNAME=		ncbi
PKGNAME=		ncbi-bin-${PKG_VER}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/20060301/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox/
COMMENT=		Portable modular software for molecular biology

PKG_VER=		20060301
WRKSRC=			${WRKDIR}/ncbi
DIST_SUBDIR=		${PKGNAME_NOREV}

MAKE_ENV+=		PREFIX=${PREFIX:Q}

do-build:
	cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} ${CSH} ncbi/make/makedis.csh

do-install:
	@${ECHO} "Installing NCBI toolkit"
	@${ECHO} "Installing docs"
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ncbi
	@${CP} -fr ${WRKSRC}/doc/*  ${PREFIX}/share/doc/ncbi
	@${ECHO} "Installing programs"
.for PROGRAM in asn2ff asn2gb asn2idx asn2xml asndhuff asntool bl2seq blast blastall blastall_old blastcl3 blastclust blastpgp cdscan checksub copymat debruijn demo_regexp demo_regexp_grep dosimple entrcmd errhdr fa2htgs fastacmd findspl formatdb formatrpsdb gene2xml getfeat getmesh getpub getseq gil2bin idfetch impala indexpub makemat makeset megablast ncbisort rpsblast seedtop seqtest tbl2asn test_regexp testcore testobj testval vecscreen wblast2.REAL wblast2_cs.REAL
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${PREFIX}/bin
.endfor
	@${ECHO} "Installing cgi programs"
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/bl2bag.cgi ${PREFIX}/libexec/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/nph-viewgif.cgi ${PREFIX}/libexec/cgi-bin

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
