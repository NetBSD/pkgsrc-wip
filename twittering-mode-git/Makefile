# $NetBSD: Makefile,v 1.10 2013/09/09 14:51:58 makoto Exp $

# M-x twittering-mode-version shows twittering-mode-vHEAD,
# but just for convenience:
DISTNAME=	twittering-mode-3.0.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hayamiz/twittering-mode/
COMMENT=	Emacs client for twitter
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/hayamiz/twittering-mode.git
GIT_MODULE.master=	twittering-mode
PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true

WRKSRC=		${WRKDIR}/twittering-mode
NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../wip/emacs-git/modules.mk"
# Avoid single file spread out just under site-lisp directory.
# And directory name should get higher precedence, so begins with 'a'.
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/a-files

# for make test only
REPLACE_BASH=	test/run-test.sh
TEST_TARGET=	check

do-install:
	${INSTALL_DATA}   ${WRKSRC}/twittering-mode.el  ${DESTDIR}${INSTALLATION_DIRS}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
