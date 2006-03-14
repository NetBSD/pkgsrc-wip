# $NetBSD: Makefile,v 1.11 2006/03/14 01:27:59 jlamwww Exp $

DISTNAME=	cjk-4.6.0
PKGNAME=	cjk-latex-4.6.0
CATEGORIES=	print
MASTER_SITES=	http://cjk.ffii.org/

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	The CJK (Chinese, Japanese, Korean) package for LaTeX

DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk

TEX_ACCEPTED=	teTeX3

MAKE_ENV+=	TEXMFDIRS=${TEXMFDIRS:Q}

post-extract:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.cjk
	${CHMOD} +x ${WRKSRC}/utils/hbf2gf/configure

pre-install:
	${FIND} ${WRKSRC}/texinput -type f -name '*.orig' | ${XARGS} ${RM} -f

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
