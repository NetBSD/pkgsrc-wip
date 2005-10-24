# $NetBSD: Makefile,v 1.4 2005/10/24 17:10:40 rillig Exp $
#

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rdbi/}
MAINTAINER=     mchittur@cs.nmsu.edu
HOMEPAGE=	http://rdbi.sourceforge.net/
COMMENT=        Provides interface between R and PostgreSQL

R_PKGNAME=      Rdbi.PgSQL
R_PKGVER=       0.1-2

DEPENDS+=	R-Rdbi>=0.1.2:../../wip/R-Rdbi

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/Rdbi.PgSQL
MAKE_ENV+=	PREFIX=${PREFIX}

post-patch:
	${SED} -e 's:@PG_INC_PATH@:${PREFIX}/include:g' ${WRKSRC}/configure > ${WRKSRC}/configure.tmp
	${MV} ${WRKSRC}/configure.tmp ${WRKSRC}/configure
	${SED} -e 's:@PG_LIB_PATH@:${PREFIX}/lib:g' ${WRKSRC}/configure > ${WRKSRC}/configure.tmp
	${MV} ${WRKSRC}/configure.tmp ${WRKSRC}/configure
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
