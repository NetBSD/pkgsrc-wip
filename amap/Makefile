# $NetBSD: Makefile,v 1.3 2004/04/25 07:08:27 blef Exp $
#

DISTNAME=       amap-4.5
CATEGORIES=     net security
MASTER_SITES=   http://www.thc.org/releases/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://www.thc.org/
COMMENT=        Applications and Services scanner

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

pre-configure:
	@${CP} ${WRKSRC}/configure ${WRKSRC}/configure.patched
	@${CP} ${WRKSRC}/amap.h ${WRKSRC}/amap.h.patched

	@${SED} -e 's|@PREFIX@|${PREFIX}|g' -e 's|@MANDIR@|${PREFIX}/man|g' \
		< ${WRKSRC}/configure.patched > ${WRKSRC}/configure

	@${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/amap.h.patched > ${WRKSRC}/amap.h

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/amap

	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.rpc ${PREFIX}/share/amap

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
