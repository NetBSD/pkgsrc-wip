# $NetBSD: Makefile,v 1.1.1.1 2008/08/29 02:15:33 phonohawk Exp $
#
DISTNAME=		haskell-mode-2.4
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.iro.umontreal.ca/~monnier/elisp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} && \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		EMACS=${EMACS_BIN}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode
	${INSTALL_DATA} ${WRKSRC}/*.el  ${EMACS_LISPPREFIX}/haskell-mode
	${INSTALL_DATA} ${WRKSRC}/*.elc ${EMACS_LISPPREFIX}/haskell-mode

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
