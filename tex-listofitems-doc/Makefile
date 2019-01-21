# $NetBSD$

DISTNAME=	listofitems
PKGNAME=	tex-${DISTNAME}-doc-1.6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/generic/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/listofitems
COMMENT=	Documentation for tex-listofitems
LICENSE=	lppl-1.3c

NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/doc/latex/listofitems

do-build:

do-install:
	cd ${WRKSRC} && \
	for f in listofitems-en.pdf listofitems-en.tex \
		listofitems-fr.pdf listofitems-fr.tex; \
	do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/listofitems/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
