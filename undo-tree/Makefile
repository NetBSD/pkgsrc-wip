# $NetBSD: Makefile,v 1.1.1.1 2010/02/22 03:52:50 phonohawk Exp $
#

DISTNAME=	undo-tree
PKGNAME=	${DISTNAME}-0.1.6
CATEGORIES=	editors
MASTER_SITES=	http://www.dr-qubit.org/${DISTNAME}/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.emacswiki.org/emacs/UndoTree
COMMENT=	Treat Emacs undo history as a tree

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
