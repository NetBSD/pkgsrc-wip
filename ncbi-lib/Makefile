# $NetBSD: Makefile,v 1.4 2005/04/19 23:52:42 daprice Exp $
#

DISTNAME=		ncbi
PKGNAME=		ncbi-lib-${PKG_VER}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/20040505/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox
COMMENT=		Portable, modular software for molecular biology

PKG_VER=		20040505
WRKSRC=			${WRKDIR}/ncbi
DIST_SUBDIR=		${PKGNAME}
USE_X11=		yes

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
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/ncbi
.for LIB in libblast.a libblastapi.a libncbi.a libncbiCacc.a \
	    libncbiNacc.a libncbiacc.a libncbicdr.a libncbiid1.a \
	    libncbimmdb.a libncbiobj.a libncbitool.a libnetblast.a \
	    libddvlib.a libncbicn3d.a libncbidesk.a libncbimla.a \
	    libvibgif.a libvibnet.a libvibrant.a libncbitxc2.a \
	    libnetcli.a libnetentr.a libregexp.a ncbithr.o
	@${INSTALL_DATA} ${WRKSRC}/lib/${LIB}  ${PREFIX}/lib/ncbi
.endfor
	@${ECHO} "Installing include files"
	@${INSTALL_DATA_DIR} ${PREFIX}/include/ncbi
	@${INSTALL_DATA_DIR} ${PREFIX}/include/ncbi/connect
.for INCLUDE in *
	@${INSTALL_DATA} ${WRKSRC}/include/${INCLUDE}.h ${PREFIX}/include/ncbi
.endfor
.for INCLUDE in *
	@${INSTALL_DATA} ${WRKSRC}/connect/${INCLUDE}.* ${PREFIX}/include/ncbi/connect/
.endfor

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

