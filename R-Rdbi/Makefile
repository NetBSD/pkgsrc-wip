# $NetBSD: Makefile,v 1.1.1.1 2004/11/26 18:48:27 daprice Exp $
#

CATEGORIES=	databases math
MASTER_SITES=	http://easynews.dl.sourceforge.net/sourceforge/rdbi/ \
		http://aleron.dl.sourceforge.net/sourceforge/rdbi/ \
		http://umn.dl.sourceforge.net/sourceforge/rdbi/ \
		http://unc.dl.sourceforge.net/sourceforge/rdbi/

MAINTAINER=    	hdp@cs.nmsu.edu
HOMEPAGE=	http://rdbi.sourceforge.net/
COMMENT=        Generic R database interface

R_PKGNAME=      Rdbi
R_PKGVER=       0.1-2

DEPENDS+=	postgresql74-lib>=7.4.3:../../databases/postgresql74-lib

WRKSRC=		${WRKDIR}/Rdbi

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
