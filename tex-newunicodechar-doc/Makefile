# $NetBSD$

DISTNAME=	newunicodechar
PKGNAME=	tex-${DISTNAME}-doc-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/texarchive/macros/latex/contrib/newunicodechar
COMMENT=	Documentation for tex-newunicodechar
LICENSE=	lppl-1.3c

NO_CONFIGURE=		YES
INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/doc/latex/newunicodechar

do-build:

do-install:
	cd ${WRKSRC} && for f in newunicodechar.pdf; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/newunicodechar/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
