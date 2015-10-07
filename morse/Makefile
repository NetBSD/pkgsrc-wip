# $NetBSD$

DISTNAME=	morse-2.5
CATEGORIES=	ham
MASTER_SITES=	http://www.catb.org/~esr/morse-classic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/morse-classic/
COMMENT=	Morse-code training program and QSO generator
LICENSE=	original-bsd

MAKE_FLAGS+=	DEVICE=OSS
#USE_TOOLS+=	pkg-config

LDFLAGS+=	${LIBOSSAUDIO}
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	morse.d/beepOSS.c
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/morse ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/QSO ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/morse.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/QSO.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MV} ${DESTDIR}${PREFIX}/bin/morse ${DESTDIR}${PREFIX}/bin/morsec
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/morse.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/morsec.1

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
