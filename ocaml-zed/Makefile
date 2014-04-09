# $NetBSD: Makefile,v 1.2 2014/04/09 00:54:58 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	zed-1.2
CATEGORIES=	textproc
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/944/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/zed/
COMMENT=	Zed is an abstract engine for text edition
LICENSE=	modified-bsd

USE_LANGUAGES=  c
HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix "${PREFIX}" --destdir "${DESTDIR}"

SUBST_CLASSES+= destdir
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

DEPENDS+=       ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=       ocaml-react-[0-9]*:../../devel/ocaml-react
DEPENDS+=       ocaml-camomile>=0.8:../../wip/ocaml-camomile

USE_TOOLS+=     gmake

do-configure:
	cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ocaml setup.ml -build

pre-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
