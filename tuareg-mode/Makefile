# $NetBSD: Makefile,v 1.12 2012/10/07 17:11:34 asau Exp $

DISTNAME=	tuareg-mode-1.46.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel editors
MASTER_SITES=	http://www-rocq.inria.fr/~acohen/tuareg/mode/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www-rocq.inria.fr/~acohen/tuareg/
COMMENT=	GNU Emacs/XEmacs major mode for editing Caml and OCaml programs

NO_BUILD=	yes

SRCS=		camldebug.el sym-lock.el tuareg.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS} \
		${DESTDIR}${EMACS_LISPPREFIX}/

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
