# $NetBSD: Makefile,v 1.0 2024/05/12 09:00:00 dkazankov Exp $

VERSION=	0.5.1
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCamlPro/}
GITHUB_PROJECT=	ocplib-simplex
GITHUB_TAG=	v${VERSION}

HOMEPAGE=	https://github.com/OCamlPro/ocplib-simplex
COMMENT=	Ocplib-simplex library implements a simplex algorithm
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/ocplib-simplex

OCAML_USE_DUNE=		yes
OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"
#.include "../../wip/ocaml-odoc/buildlink3.mk"
#.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
