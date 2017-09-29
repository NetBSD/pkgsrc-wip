# $NetBSD: Makefile,v 1.1 2015/02/11 15:58:20 phonohawk Exp $

DISTNAME=	elscreen-current-0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	misc

CONFLICTS+=	elscreen-[0-9]*

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/knu/elscreen
COMMENT=	Window manager within Emacs
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	knu
GIT_REPO.knu=		git://github.com/knu/elscreen.git
GIT_MODULE.knu=		elscreen

WRKSRC=		${WRKDIR}/elscreen
USE_LANGUAGES=	# none

do-build:
	cd ${WRKSRC} && \
	${EMACS_BIN} -batch -f batch-byte-compile *.el

INSTALLATION_DIRS+= ${EMACS_LISPPREFIX}/elscreen
INSTALLATION_DIRS+= share/doc/elscreen

do-install:
.for files in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${files} ${DESTDIR}${EMACS_LISPPREFIX}/elscreen
.endfor
.for files in COPYING GF-QuickStart GF-README Readme.md
	${INSTALL_DATA} ${WRKSRC}/${files} ${DESTDIR}${PREFIX}/share/doc/elscreen
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
