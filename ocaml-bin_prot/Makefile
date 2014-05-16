# $NetBSD: Makefile,v 1.1 2014/05/16 02:23:10 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	bin_prot-111.03.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/111.03.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/bin_prot/
COMMENT=	Read and write OCaml-values in a type-safe binary protocol
LICENSE=	apache-2.0

SUBST_CLASSES+=         destdir
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

.include "../../wip/mk/ocaml-oasis.mk"
.include "../../mk/bsd.pkg.mk"
