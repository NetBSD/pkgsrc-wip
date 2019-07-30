# $NetBSD$

GITHUB_PROJECT=	lablgtk
GITHUB_TAG=	${VERSION}
VERSION=	3.0.beta6
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}3-3.0beta6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/garrigue/lablgtk/
COMMENT=	GTK+ 3.x bindings for OCaml
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	lablgtk3

MAKE_JOBS_SAFE=		no
BUILD_TARGET=		world
INSTALLATION_DIRS=	bin
CONFIGURE_ENV+=		OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"

.include "../../mk/ocaml.mk"

.include "options.mk"

#.include "../../lang/camlp4/buildlink3.mk"
.include "../../wip/ocaml-cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
