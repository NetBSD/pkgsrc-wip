# $NetBSD$

VERSION=	7.1-beta

GITHUB_PROJECT=	geneweb
GITHUB_TAG=	refs/tags/v${VERSION}
DISTNAME=	v${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=geneweb/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/geneweb/geneweb/
COMMENT=	GeneWeb is a genealogy database that runs as a web server
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/geneweb-${VERSION}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

OCAML_USE_DUNE=		yes
#OCAML_FINDLIB_DIRS=	cairo2
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

RCD_SCRIPTS=	geneweb

.include "../../mk/bsd.prefs.mk"

do-configure:
	 cd ${WRKSRC} && ocaml ./configure.ml

BUILD_TARGET=	build

#.include "../../lang/camlp5/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
