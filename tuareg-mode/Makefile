# $NetBSD: Makefile,v 1.1.1.1 2005/06/05 13:39:07 jtonio Exp $
#

DISTNAME=		tuareg-mode-1.45.0
CATEGORIES=		wip devel editors
MASTER_SITES=		http://www-rocq.inria.fr/~acohen/tuareg/mode/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reilles@loria.fr
HOMEPAGE=		http://www-rocq.inria.fr/~acohen/tuareg/
COMMENT=		GNU Emacs/XEmacs major mode for editing Caml and OCaml programs

NO_BUILD=yes

SRCS= camldebug.el sym-lock.el tuareg.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS} \
		${EMACS_LISPPREFIX}/

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
