# $NetBSD: Makefile,v 1.1 2014/06/05 21:26:12 leot1990 Exp $

DISTNAME=	cmusfm-0.2.0
CATEGORIES=	audio
MASTER_SITES=	-https://github.com/Arkq/cmusfm/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Arkq/cmusfm
COMMENT=	Last.fm standalone scrobbler for the cmus music player
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile.
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's/gcc/${CC:Q}/'
SUBST_SED.makefile+=	-e 's,^CFLAGS *=,CFLAGS +=,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *=,LDFLAGS +=,'

INSTALLATION_DIRS=	bin ${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/cmusfm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmusfm ${DESTDIR}${PREFIX}/bin/cmusfm
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
