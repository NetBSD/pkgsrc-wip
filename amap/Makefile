# $NetBSD: Makefile,v 1.6 2005/04/11 21:09:41 tvierling Exp $
#

DISTNAME=       amap-4.7
CATEGORIES=     net security
MASTER_SITES=   http://www.thc.org/releases/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://www.thc.org/
COMMENT=        Applications and Services scanner

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${PREFIX}/share/amap
	${INSTALL_DATA} ${WRKSRC}/appdefs.rpc ${PREFIX}/share/amap

SUBST_CLASSES=		loc conf
SUBST_FILES.loc=	amap.h
SUBST_STAGE.loc=	pre-configure
SUBST_SED.loc=		-e 's|/usr/local|${PREFIX}|g' \
			-e 's|AMAP_PREFIX\"/bin\"|\"${PREFIX}/bin\"|g'
SUBST_MESSAGE.loc=	"Fixing program file locations."

SUBST_FILES.conf=	configure
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e 's|@PREFIX@|${PREFIX}|g' \
			-e 's|@MANDIR@|${PREFIX}/man|g'
SUBST_MESSAGE.conf=	"Fixing configure script."

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
