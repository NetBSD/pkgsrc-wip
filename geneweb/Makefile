# $NetBSD$

VERSION=	7.1-beta
GITHUB_PROJECT=	geneweb
GITHUB_TAG=	refs/tags/v${VERSION}
DISTNAME=	v${VERSION}
PKGNAME=	${GITHUB_PROJECT}-7.1b1
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=geneweb/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/geneweb/geneweb/
COMMENT=	GeneWeb is a genealogy database that runs as a web server
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/geneweb-${VERSION}
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

OCAML_USE_DUNE=		yes
#OCAML_FINDLIB_DIRS=	cairo2
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

RCD_SCRIPTS=		geneweb

.include "../../mk/bsd.prefs.mk"

do-configure:
	 cd ${WRKSRC} && ocaml ./configure.ml

BUILD_TARGET=	build

.include "../../devel/ocaml-ppx_import/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../lang/camlp5/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../textproc/ocaml-markup/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../www/ocaml-uri/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
