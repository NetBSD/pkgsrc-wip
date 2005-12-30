# $NetBSD: Makefile,v 1.3 2005/12/30 19:55:18 mchittur Exp $
#

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdbi/}

MAINTAINER=    	mchittur@cs.nmsu.edu
HOMEPAGE=	http://rdbi.sourceforge.net/
COMMENT=        Generic R database interface

R_PKGNAME=      Rdbi
R_PKGVER=       0.1-2

DEPENDS+=	postgresql74-lib>=7.4.3:../../databases/postgresql74-lib
 
WRKSRC=		${WRKDIR}/Rdbi

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
