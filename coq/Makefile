# $NetBSD: Makefile,v 1.1.1.1 2010/03/11 14:37:18 othyro Exp $
#

DISTNAME=		coq-8.2pl1
CATEGORIES=		math
MASTER_SITES=		http://coq.inria.fr/distrib/V8.2pl1/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://coq.inria.fr/
COMMENT=		Coq is a formal proof management system
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-bindir ${DESTDIR}${PREFIX}/bin
CONFIGURE_ARGS+=	-libdir ${DESTDIR}${PREFIX}/lib/coq
CONFIGURE_ARGS+=	-mandir ${DESTDIR}${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-docdir ${DESTDIR}${PREFIX}/share/doc/coq
CONFIGURE_ARGS+=	-emacslib ${DESTDIR}${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-coqdocdir ${DESTDIR}${PREFIX}/share/texmf/tex/latex/coq

USE_TOOLS+=		gmake

DEPENDS+=               bash-[0-9]*:../../shells/bash

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${DESTDIR}${PREFIX}/bin/bash
REPLACE_FILES.bash=	configure dev/v8-syntax/check-grammar install.sh

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-build
SUBST_FILES.bash=	Makefile Makefile.stage1
SUBST_SED.bash=		-e "s,/bin/bash,${DESTDIR}${PREFIX}/bin/bash,g"
SUBST_MESSAGE.bash=	Fixing harcoded bash path

LDFLAGS+=		-L${BUILDLINK_PREFIX.gtk2}/lib

BUILD_TARGET=		# empty

.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/camlp5/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
