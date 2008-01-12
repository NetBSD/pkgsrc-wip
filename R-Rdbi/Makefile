# $NetBSD: Makefile,v 1.5 2008/01/12 23:20:56 thomasklausner Exp $
#

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdbi/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	http://rdbi.sourceforge.net/
COMMENT=	Generic R database interface

R_PKGNAME=	Rdbi
R_PKGVER=	0.1-2

DEPENDS+=	postgresql82-client>=8.2.0:../../databases/postgresql82-client

WRKSRC=		${WRKDIR}/Rdbi

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
