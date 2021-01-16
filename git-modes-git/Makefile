# $NetBSD: Makefile,v 1.3 2014/10/07 23:48:17 makoto Exp $

DISTNAME=	git-modes-git-0.1
CATEGORIES=	devel
GIT_REPO=	https://github.com/magit/git-modes.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/git-modes
COMMENT=	Git-modes submodule for magit.el
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

BUILD_TARGET=	lisp
AUTO_MKDIRS=	yes
INSTALLATION_DIRS+= share/emacs/site-lisp/git-modes

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc \
		${DESTDIR}${PREFIX}/share/emacs/site-lisp/git-modes

.include "../../wip/emacs-git/modules.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
