# $NetBSD$

DISTNAME=	newunicodechar
PKGNAME=	tex-${DISTNAME}-1.2
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/texarchive/macros/latex/contrib/newunicodechar
COMMENT=	Definitions of the meaning of Unicode characters
LICENSE=	lppl-1.3c

NO_CONFIGURE=		YES
INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/newunicodechar

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

do-build:
	cd ${WRKSRC} && latex newunicodechar.ins

do-install:
	cd ${WRKSRC} && for f in newunicodechar.sty; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/newunicodechar/$$f; \
	done

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
