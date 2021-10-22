# $NetBSD: Makefile,v 1.1 2021/02/27 21:09:40 leot Exp $

DISTNAME=	ploot-v1.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/ploot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/ploot
COMMENT=	Simple plotting tools
LICENSE=	isc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

CFLAGS+=	-D_XOPEN_SOURCE=600

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Honor *FLAGS and dynamic link
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/CFLAGS/s/=/+=/'
SUBST_SED.makefile+=	-e 's/LFLAGS/LDFLAGS/g'
SUBST_SED.makefile+=	-e '/LDFLAGS/s/=/+=/'
SUBST_SED.makefile+=	-e '/LDFLAGS/s/-static//'

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
.for _p_ in ploot-farbfeld ploot-feed ploot-braille ploot-text
	${INSTALL_PROGRAM} ${WRKSRC}/${_p_} ${DESTDIR}${PREFIX}/bin
.endfor
.for _m_ in ploot-farbfeld.1 ploot-feed.1
	${INSTALL_MAN} ${WRKSRC}/${_m_} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for _m_ in ploot-tsv.5
	${INSTALL_MAN} ${WRKSRC}/${_m_} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
.endfor

.include "../../mk/bsd.pkg.mk"
