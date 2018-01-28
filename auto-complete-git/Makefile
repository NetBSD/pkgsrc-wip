# $NetBSD: Makefile,v 1.1 2012/10/12 11:16:49 thomasklausner Exp $
#

DISTNAME=	auto-complete-0
CATEGORIES=	editors

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cx4a.org/software/auto-complete/
COMMENT=	Auto Complete Mode for emacs
LICENSE=	gnu-gpl-v3

DEPENDS+=	${EMACS_PKGNAME_PREFIX}fuzzy-el-[0-9]*:../../wip/fuzzy-el-current
DEPENDS+=	${EMACS_PKGNAME_PREFIX}popup-el-[0-9]*:../../wip/popup-el-current

GIT_REPOSITORIES=	auto-complete
GIT_REPO.auto-complete=	git://github.com/auto-complete/auto-complete.git
.include "../../wip/mk/git-package.mk"

WRKSRC=			${WRKDIR}/auto-complete

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX}
MESSAGE_SUBST+=		PKGBASE=${PKGBASE}
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/${PKGBASE}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/${PKGBASE}/ac-dict
INSTALLATION_DIRS+=	share/doc/auto-complete

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -Q -L ${EMACS_LISPPREFIX}/popup-el -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/dict/* ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}/ac-dict
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/auto-complete

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
