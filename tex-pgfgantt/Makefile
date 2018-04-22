# $NetBSD$

DISTNAME=	pgfgantt
PKGNAME=	tex-${DISTNAME}-5.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=graphics/pgf/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/pgfgantt
COMMENT=	Draw Gantt charts with TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/pgfgantt

do-install:
	cd ${WRKSRC}/${DISTNAME} && ${LOCALBASE}/bin/latex pgfgantt.ins
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/pgfgantt.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/pgfgantt/pgfgantt.sty

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
