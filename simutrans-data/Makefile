# $NetBSD$

PKGNAME=	simutrans-data-0.1
CATEGORIES=	games
DISTNAME=	simutrans-data
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simutrans/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.simutrans.com/en/paksets/
COMMENT=	Game data for Simutrans 
#LICENSE=	# TODO: (see mk/license.mk)

NO_BUILD=	yes


#DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

post-extract:
		${FIND} ${WRKDIR} -type f -exec ${CHMOD} 0644 {} \;

do-install:	
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/simtrans
		${CP} -r ${WRKSRC} ${DESTDIR}${PREFIX}/share/

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
