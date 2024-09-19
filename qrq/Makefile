# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	qrq-0.3.1
CATEGORIES=	ham
MASTER_SITES=	http://fkurz.net/ham/qrq/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fkurz.net/ham/qrq.html
COMMENT=	Open source Morse telegraphy trainer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run
AUTO_MKDIRS=	yes

LDFLAGS+=	${LIBOSSAUDIO}

REPLACE_PERL=		qrqscore

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	qrq.c
SUBST_FILES.oss+=	qrqrc
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_MESSAGE.destdir=	Fixing prefix.
SUBST_FILES.destdir=	Makefile
SUBST_SED.destdir=	-e 's,/usr,${PREFIX},'

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_SED.pthread+=	-e 's/-lpthread/${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}/g'


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qrq ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/qrqscore ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qrq.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/callbase.qcb ${DESTDIR}${PREFIX}/share/qrq
	${INSTALL_MAN} ${WRKSRC}/english.qcb ${DESTDIR}${PREFIX}/share/qrq
	${INSTALL_MAN} ${WRKSRC}/qrqrc ${DESTDIR}${PREFIX}/share/qrq
	${INSTALL_MAN} ${WRKSRC}/toplist ${DESTDIR}${PREFIX}/share/qrq


.include "../../mk/oss.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
