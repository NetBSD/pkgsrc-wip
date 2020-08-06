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

.include "../../mk/fonts.mk"

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+= ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS.txt ${WRKSRC}/CONTRIBUTORS.txt \
		${WRKSRC}/OFL.txt ${WRKSRC}/README.md \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
