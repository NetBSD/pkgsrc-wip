# $NetBSD$

DISTNAME=	stackengine
PKGNAME=	tex-${DISTNAME}-4.0.1
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/texarchive/macros/latex/contrib/stackengine
COMMENT=	Highly customised stacking of objects
LICENSE=	lppl-1.3c

NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/stackengine

do-build:

do-install:
	cd ${WRKSRC} && for f in stackengine.sty; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/stackengine/$$f; \
	done

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
