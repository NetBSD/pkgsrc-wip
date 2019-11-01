# $NetBSD$

DISTNAME=	gen-0.5.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-cube/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}
DIST_SUBDIR=	ocaml-gen

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/c-cube/gen/
COMMENT=	Simple, efficient iterators for OCaml
LICENSE=	2-clause-bsd

OCAML_USE_DUNE=		yes
TEST_TARGET=		test

.include "../../mk/ocaml.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
