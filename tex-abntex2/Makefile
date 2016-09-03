# $NetBSD$

VERSION=	1.9.6
RELYEAR=	2016
RELDATE=	2016-02-26

GITHUB_PROJECT=	abntex2
DISTNAME=	${RELDATE}-v${VERSION}-ctan
PKGNAME=	tex-abntex2-${VERSION}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=abntex/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}

# TODO: release version of dependencies?
DEPENDS+=	tex-enumitem>=3.5.2:../../print/tex-enumitem
DEPENDS+=	tex-memoir>=3.7e:../../print/tex-memoir
DEPENDS+=	tex-textcase>=0.07:../../print/tex-textcase
DEPENDS+=	tex-hyperref>=6.83m:../../print/tex-hyperref

SUBST_CLASSES+=			install-path
SUBST_STAGE.install-path =	pre-configure
SUBST_MESSAGE.install-path =	Fixing INSTALL_PATH
SUBST_FILES.install-path =	Makefile
SUBST_SED.install-path =	-e 's/^INSTALL_PATH =/INSTALL_PATH ?=/'

MAKE_ENV+=	INSTALL_PATH=${PREFIX}/share/texmf-dist

SUBST_CLASSES+=			relinfo
SUBST_STAGE.relinfo=		pre-configure
SUBST_MESSAGE.relinfo=		Filling in release information
SUBST_FILES.relinfo=		bibtex/bst/abntex2/*.bst
SUBST_FILES.relinfo+=		doc/latex/abntex2/README
SUBST_FILES.relinfo+=		doc/latex/abntex2/examples/*.tex
SUBST_FILES.relinfo+=		tex/latex/abntex2/*.cls
SUBST_FILES.relinfo+=		tex/latex/abntex2/*.sty
SUBST_SED.relinfo=		-e 's|<CURRENT_DATE>|${RELDATE:S,-,/,g}|g'
SUBST_SED.relinfo+=		-e 's/<COPYRIGHT_YEAR>/${RELYEAR}/g'
SUBST_SED.relinfo+=		-e 's/<VERSION>/${VERSION}/g'

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	https://github.com/abntex/abntex2/
COMMENT=	Support for ABNT documentation standards
#LICENSE=	# TODO: (see mk/license.mk)

.include "../../print/kpathsea/texmf.mk"

.include "../../mk/bsd.pkg.mk"
