# $NetBSD: Makefile,v 1.4 2004/10/26 14:57:25 poppnk Exp $
#

DISTNAME=       amap-4.7
CATEGORIES=     net security
MASTER_SITES=   http://www.thc.org/releases/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://www.thc.org/
COMMENT=        Applications and Services scanner

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.rpc ${PREFIX}/share/amap

SUBST_CLASSES=appdef man pfx

SUBST_FILES.appdef=amap.h
SUBST_STAGE.appdef=post-configure
SUBST_SED.appdef=-e 's|/bin|/share/amap|g'

# XXX it must use CONFIGURE_ARGS+=--prefix=${PREFIX}
SUBST_FILES.man=configure
SUBST_STAGE.man=pre-configure
SUBST_SED.man=-e 's|@PREFIX@|${PREFIX}|g' \
	-e 's|@MANDIR@|${PREFIX}/man|g'

SUBST_FILES.pfx=amap.h
SUBST_STAGE.pfx=pre-configure
SUBST_SED.pfx=-e 's|@PREFIX@|${PREFIX}|g'

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
