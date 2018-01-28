# $NetBSD: Makefile,v 1.16 2012/10/14 17:57:23 asau Exp $
#

PKGNAME=		ncbi-lib-20120620
DISTNAME=		ncbi
DIST_SUBDIR=		ncbi-${PKGVERSION_NOREV}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/${PKGVERSION_NOREV}/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox/
COMMENT=		Portable, modular software for molecular biology

WRKSRC=			${WRKDIR}/ncbi

MAKE_ENV+=		PREFIX=${PREFIX}

post-extract:
	${MV} ${WRKSRC}/make/makedis.csh ${WRKSRC}/make/makedis.csh.in

do-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@X11BASE@:${X11BASE}:g' ${WRKSRC}/make/makedis.csh.in > ${WRKSRC}/make/makedis.csh
	${CHMOD} 755 ${WRKSRC}/make/makedis.csh

do-build:
	cd ${WRKSRC}/.. && ${SETENV} ${MAKE_ENV} ${CSH} ncbi/make/makedis.csh

do-install:
	@${ECHO} "Installing NCBI toolkit"
	@${ECHO} "Installing Lib"
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ncbi
	@${CP} -fr ${WRKSRC}/lib/*  ${DESTDIR}${PREFIX}/lib/ncbi
	@${ECHO} "Installing include files"
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/ncbi
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/ncbi/connect
	@${CP} -fr ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include/ncbi
	@${CP} -fr ${WRKSRC}/connect/*.* ${DESTDIR}${PREFIX}/include/ncbi/connect/

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
