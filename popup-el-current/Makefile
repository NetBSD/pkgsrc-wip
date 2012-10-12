# $NetBSD: Makefile,v 1.1 2012/10/12 11:15:24 thomasklausner Exp $
#

DISTNAME=	popup-el-0
CATEGORIES=	editors

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/auto-complete/popup-el
COMMENT=	Visual popup user interface library for emacs
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	popup-el
GIT_REPO.popup-el=	git://github.com/auto-complete/popup-el.git
.include "../../wip/mk/git-package.mk"

WRKSRC=			${WRKDIR}/popup-el

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -Q -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
