# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:37 shattered Exp $
#

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdbi/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	http://rdbi.sourceforge.net/
COMMENT=	Generic R database interface

R_PKGNAME=	Rdbi
R_PKGVER=	0.1-2

DEPENDS+=	postgresql74-lib>=7.4.3:../../databases/postgresql74-lib

WRKSRC=		${WRKDIR}/Rdbi

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
