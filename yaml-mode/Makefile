# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=	yaml-mode-0.0.7
CATEGORIES=	editors

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.emacswiki.org/emacs/YamlMode
COMMENT=	Emacs major mode for editing YAML files
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/yoshiki/${PKGBASE}.git
GIT_MODULE.master=	${PKGBASE}

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

do-build:
	cd ${WRKSRC} \
		&& ${EMACS_BIN} -batch -f batch-byte-compile ${PKGBASE}.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el    ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc   ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
