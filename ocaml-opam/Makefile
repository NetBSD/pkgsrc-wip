# $NetBSD$

DISTNAME=	opam-full-2.5.2
PKGNAME=	ocaml-${DISTNAME:S/-full//}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/opam/releases/download/${PKGVERSION_NOREV}/}

MAINTAINER=	kit-ty-kate@exn.st
HOMEPAGE=	https://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	rsync-[0-9]*:../../net/rsync

BUILD_DEPENDS+=	ocaml-dune-[0-9]*:../../devel/ocaml-dune

MAKE_JOBS_SAFE=	no
USE_LANGUAGES+=	c c++
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-vendored-deps --with-mccs

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
