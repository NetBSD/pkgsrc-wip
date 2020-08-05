# $NetBSD$

DISTNAME=	Montserrat-7.210
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=JulietaUla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/JulietaUla/Montserrat/
COMMENT=	Geometric sans-serif typeface font by Julieta Ulanovsky
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none
NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	set -e; \
	cd ${WRKSRC}/fonts/ttf && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/AUTHORS.txt ${WRKSRC}/CONTRIBUTORS.txt \
		${WRKSRC}/OFL.txt ${WRKSRC}/README.md \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
