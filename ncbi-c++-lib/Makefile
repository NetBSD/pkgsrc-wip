# $NetBSD: Makefile,v 1.1.1.1 2005/03/17 21:16:12 daprice Exp $
#

DISTNAME=		ncbi_cxx--Nov_30_2004
PKGNAME=		ncbi_cxx-lib-20041130
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools++/2004/Nov_30_2004/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox/index.cgi
COMMENT=		Libraries needed by apps dependent on NCBI C++ toolkit

CONFLICTS=		ncbi_cxx-lib-[0-9]*
USE_X11=		YES
USE_BUILDLINK3=		YES

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_SCRIPT} --prefix=${PREFIX} --without-debug --with-fltk=${PREFIX} --with-wxwin=${PREFIX}

.include "../../x11/gtk/buildlink3.mk"
.include "../../wip/ncbi-lib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
