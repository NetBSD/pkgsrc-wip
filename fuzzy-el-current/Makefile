# $NetBSD: Makefile,v 1.1 2012/10/12 11:16:06 thomasklausner Exp $
#

DISTNAME=	fuzzy-el-0
CATEGORIES=	editors

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/auto-complete/fuzzy-el
COMMENT=	Fuzzy matching library for emacs

GIT_REPOSITORIES=	fuzzy-el
GIT_REPO.fuzzy-el=	git://github.com/auto-complete/fuzzy-el.git
.include "../../wip/mk/git-package.mk"

WRKSRC=			${WRKDIR}/fuzzy-el

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -Q -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
