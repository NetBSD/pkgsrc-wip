# $NetBSD$

DISTNAME=	stackengine
PKGNAME=	tex-${DISTNAME}-doc-4.0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/texarchive/macros/latex/contrib/stackengine
COMMENT=	Documentation for tex-stackengine
LICENSE=	lppl-1.3c

NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/doc/latex/stackengine

do-build:

do-install:
	cd ${WRKSRC} && for f in stackengine.pdf stackengine.tex; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/stackengine/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
