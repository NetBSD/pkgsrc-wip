# $NetBSD: Makefile,v 1.3 2014/10/07 23:48:17 makoto Exp $
DISTNAME=	git-modes-git-0.1
CATEGORIES=	devel
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/magit/git-modes.git
GIT_MODULE.master=	git-modes
GIT_ENV.master+=	GIT_SSL_NO_VERIFY=true

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/git-modes
COMMENT=	Git-modes submodule for magit.el

WRKSRC=		${WRKDIR}/git-modes

USE_TOOLS+=	gmake

BUILD_TARGET=		lisp
INSTALLATION_DIRS=	${DESTDIR}${PREFIX}/share/emacs/site-lisp/git-modes
AUTO_MKDIRS=		yes

do-install:
		${INSTALL_DATA_DIR}	${INSTALLATION_DIRS}
		${INSTALL_DATA} ${WRKSRC}/*.el  ${WRKSRC}/*.elc ${INSTALLATION_DIRS}

.include "../../wip/emacs-git/modules.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
