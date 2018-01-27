# $NetBSD: Makefile,v 1.1 2013/09/12 18:01:46 thomasklausner Exp $

DISTNAME=		org-caldav-0.0
CATEGORIES=		time net
MASTER_SITES=		https://github.com/dengste/org-caldav

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dengste/org-caldav
COMMENT=		Caldav sync for Emacs Orgmode

GIT_REPOSITORIES=	org-caldav
GIT_REPO.org-caldav=	git://github.com/dengste/org-caldav.git

WRKSRC=			${WRKDIR}/org-caldav
EGG_NAME=		${DISTNAME}.dev
INSTALLATION_DIRS=	share/doc/org-caldav
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -L . -Q -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/org-caldav

.include "../../editors/emacs/modules.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
