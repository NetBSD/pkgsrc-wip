# $NetBSD: Makefile,v 1.1 2014/05/21 09:06:04 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	sexplib-111.13.00
CATEGORIES=	devel
MASTER_SITES=   https://ocaml.janestreet.com/ocaml-core/111.13.00/individual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocaml-type_conv-[0-9]*:../../wip/ocaml-type_conv

SUBST_CLASSES+=         destdir
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

.include "../../wip/mk/ocaml-oasis.mk"
.include "../../mk/bsd.pkg.mk"
