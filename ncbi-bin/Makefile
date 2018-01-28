# $NetBSD: Makefile,v 1.11 2012/10/14 17:55:00 asau Exp $
#

PKGNAME=		ncbi-bin-20120620
DISTNAME=		ncbi
DIST_SUBDIR=		ncbi-${PKGVERSION_NOREV}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/${PKGVERSION_NOREV}/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox/
COMMENT=		Portable modular software for molecular biology

WRKSRC=			${WRKDIR}/ncbi

MAKE_ENV+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin libexec/cgi-bin

do-build:
	cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} ${CSH} ncbi/make/makedis.csh

do-install:
	@${ECHO} "Installing NCBI toolkit"
	@${ECHO} "Installing docs"
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ncbi
	@${CP} -fr ${WRKSRC}/doc/*  ${DESTDIR}${PREFIX}/share/doc/ncbi
	@${ECHO} "Installing programs"
.for PROGRAM in asn2ff asn2gb asn2idx asn2xml asndhuff asntool bl2seq blastall blastcl3 blastclust blastpgp cdscan checksub copymat debruijn demo_regexp demo_regexp_grep dosimple entrcmd errhdr fa2htgs fastacmd findspl formatdb formatrpsdb gene2xml getmesh getpub gil2bin idfetch impala indexpub makemat makeset megablast ncbisort rpsblast seedtop seqtest taxblast tbl2asn test_regexp testcore testobj testval vecscreen wblast2.REAL wblast2_cs.REAL
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${DESTDIR}${PREFIX}/bin
.endfor
	@${ECHO} "Installing cgi programs"
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/bl2bag.cgi ${DESTDIR}${PREFIX}/libexec/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/nph-viewgif.cgi ${DESTDIR}${PREFIX}/libexec/cgi-bin

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
