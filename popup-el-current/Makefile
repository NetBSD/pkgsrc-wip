# $NetBSD: Makefile,v 1.1 2012/10/12 11:15:24 thomasklausner Exp $

DISTNAME=	popup-el-0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/auto-complete/popup-el
COMMENT=	Visual popup user interface library for emacs
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	popup-el
GIT_REPO.popup-el=	https://github.com/auto-complete/popup-el.git
.include "../../wip/mk/git-package.mk"

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs214nox xemacs215 xemacs215nox

WRKSRC=			${WRKDIR}/popup-el

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/popup-el

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/popup-el
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/popup-el

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
