# $NetBSD: Makefile,v 1.10 2012/10/03 09:10:36 asau Exp $
#

DISTNAME=		lhs2tex-1.12
PKGREVISION=		2
CATEGORIES=		print devel
MASTER_SITES=		http://people.cs.uu.nl/andres/lhs2tex/
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=		http://people.cs.uu.nl/andres/lhs2tex/
MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Preprocessor for typesetting Haskell sources with LaTeX

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-lazylist-[0-9]*:../../print/tex-lazylist
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	share/doc/lhs2tex \
			share/texmf-dist/tex/latex/polytable \
			share/texmf-dist/tex/latex/lazylist

.include "../../lang/ghc/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-install:
.for f in doc/Guide2.pdf polytable/polytable.pdf INSTALL RELEASE
	${INSTALL_DATA} ${WRKSRC}/$f ${DESTDIR}${PREFIX}/share/doc/lhs2tex
.endfor
	${INSTALL_DATA} ${WRKSRC}/polytable/polytable.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/polytable
	${INSTALL_DATA} ${WRKSRC}/polytable/lazylist.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/lazylist

.include "../../mk/bsd.pkg.mk"
