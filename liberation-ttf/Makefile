# $NetBSD: Makefile,v 1.1.1.1 2007/05/15 13:38:49 bartoszkuzma Exp $
#

DISTNAME=	liberation-fonts-ttf-2
PKGNAME=	liberation-ttf-0.1
CATEGORIES=	fonts
MASTER_SITES=	http://www.redhat.com/f/fonts/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat

USE_TOOLS+=	gzcat tar

NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/liberation-ttf
FONTS_DIR.ttf=	${FONTDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${GZCAT} ${DISTDIR}/${DISTFILES:Q} | ${TAR} -xf -

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${FONTDIR}

	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
