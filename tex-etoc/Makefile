# $NetBSD$

DISTNAME=	etoc
PKGNAME=	tex-${DISTNAME}-1.08p
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/etoc
COMMENT=	Completely customisable TOCs
LICENSE=	lppl-1.3c

NO_CONFIGURE=		YES
INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/etoc

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

do-build:
	cd ${WRKSRC} && latex etoc.ins

do-install:
	cd ${WRKSRC} && for f in etoc.sty; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/etoc/$$f; \
	done

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
