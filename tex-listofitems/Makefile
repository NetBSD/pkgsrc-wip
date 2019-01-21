# $NetBSD$

DISTNAME=	listofitems
PKGNAME=	tex-${DISTNAME}-1.6
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/generic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/listofitems
COMMENT=	Grab items in lists using user-specified sep char
LICENSE=	lppl-1.3c

NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/listofitems

do-build:

do-install:
	cd ${WRKSRC} && for f in listofitems.sty listofitems.tex; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/listofitems/$$f; \
	done

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
