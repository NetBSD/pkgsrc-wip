# $NetBSD: Makefile,v 1.3 2010/04/13 19:17:53 emil_s Exp $
#
DISTNAME=		haskell-mode-2.7.0
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://projects.haskell.org/haskellmode-emacs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir


MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}

SRCS=                   haskell-c.el haskell-cabal.el haskell-decl-scan.el \
			haskell-doc.el haskell-font-lock.el haskell-ghci.el \
			haskell-hugs.el haskell-indent.el \
			haskell-indentation.el haskell-mode.el \
			haskell-simple-indent.el haskell-site-file.el \
			inf-haskell.el

do-build:
	for f in ${SRCS}; do \
		cd ${WRKSRC}; \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
			-l haskell-mode.el -f batch-byte-compile $$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode
	cd ${WRKSRC}; \
	${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
		${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
