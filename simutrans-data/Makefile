# $NetBSD$

PKGNAME=	simutrans-data
DISTNAME=	simupak64-120-0-1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simutrans/}
MASTER_SITES+=	-http://simutrans-germany.com/translator/data/tab/language_pack-Base+texts.zip
DISTFILES+=	language_pack-Base+texts.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/simutrans/pak64/120-0/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/simutrans
NO_BUILD=      yes
EXTRACT_ONLY=           ${DISTNAME}${EXTRACT_SUFX}

post-extract:
		${MV} ${WRKSRC}/pak/text ${WRKSRC}
		${FIND} ${WRKDIR} -type f -exec ${CHMOD} 0644 {} \;
do-install:
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/simtrans
		${CP} -r ${WRKSRC} ${DESTDIR}${PREFIX}/share/


.include "../../mk/bsd.pkg.mk"
