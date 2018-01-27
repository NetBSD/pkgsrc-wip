# $NetBSD: Makefile,v 1.2 2015/04/30 06:46:46 gschwarz Exp $

PKGNAME=	smap-0.6.0
DISTNAME=	smap-20081016
CATEGORIES=	security
MASTER_SITES=	https://downloads.openwrt.org/sources/
MASTER_SITES+=	http://mirror2.openwrt.org/sources/

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	SIP network scanner
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/smap
NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

CFLAGS+=	-DHAVE_STRNSTR
CFLAGS+=	-DHAVE_IFADDRS
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-lm
LDFLAGS+=	${PTHREAD_LDFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

SUBST_CLASSES+=		cflags
SUBST_FILES.cflags=	Makefile
SUBST_SED.cflags=	-e 's/^CFLAGS=/CFLAGS?=/g'
SUBST_SED.cflags+=	-e 's/^LDFLAGS=/LDFLAGS?=/g'
SUBST_STAGE.cflags=	post-patch

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smap ${DESTDIR}${PREFIX}/bin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
