# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:32 asau Exp $
#

DISTNAME=	emacs-ditz-0.5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/kentaro/${PKGBASE}/
COMMENT=	Emacs interface to Ditz issue tracking system
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/kentaro/${PKGBASE}.git
GIT_MODULE.master=	${PKGBASE}

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	# none

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -batch -f batch-byte-compile ditz.el

INSTALLATION_DIRS= \
	${EMACS_LISPPREFIX} \
	share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/ditz.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/ditz.elc ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/README   ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

DEPENDS+=	${RUBY_PKGPREFIX}-ditz-[0-9]*:../../wip/ruby-ditz

.include "../../wip/mk/git-package.mk"
.include "../../editors/emacs/modules.mk"
.include "../../lang/ruby/rubyversion.mk" # for ${RUBY_PKGPREFIX}
.include "../../mk/bsd.pkg.mk"
