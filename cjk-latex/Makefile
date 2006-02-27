# $NetBSD: Makefile,v 1.10 2006/02/27 18:08:47 rxg Exp $

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

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-extract:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.cjk
	${CHMOD} +x ${WRKSRC}/utils/hbf2gf/configure

pre-install:
	${FIND} ${WRKSRC}/texinput -type f -name '*.orig' | ${XARGS} ${RM} -f

post-install:
	# Edit texmf.cnf
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
