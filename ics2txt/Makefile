# $NetBSD: Makefile,v 1.1 2021/02/27 21:09:40 leot Exp $

DISTNAME=	ics2txt-v1.1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	time
MASTER_SITES=	ftp://bitreich.org/releases/ics2txt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/ics2txt
COMMENT=	Convert icalendar .ics file to plain text
# FIXME: unknown license!
#LICENSE=	isc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

CFLAGS+=	-D_XOPEN_SOURCE=600

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Honor CFLAGS
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/CFLAGS/s/=/+=/'

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

pre-install:
	${MV} ${WRKSRC}/tsv2ics.awk ${WRKSRC}/tsv2ics

do-install:
.for _p_ in ics2tree ics2tsv tsv2agenda
	${INSTALL_PROGRAM} ${WRKSRC}/${_p_} ${DESTDIR}${PREFIX}/bin
.endfor
.for _s_ in tsv2ics
	${INSTALL_SCRIPT} ${WRKSRC}/${_s_} ${DESTDIR}${PREFIX}/bin
.endfor
.for _m_ in ics2tsv.1 tsv2ics.1 tsv2agenda.1
	${INSTALL_MAN} ${WRKSRC}/${_m_} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../mk/bsd.pkg.mk"
