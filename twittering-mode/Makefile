# $NetBSD: Makefile,v 1.4 2012/10/07 17:17:53 asau Exp $

# M-x twittering-mode-version shows twittering-mode-vHEAD,
# but just for convenience:
DISTNAME=	twittering-mode-1.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hayamiz/twittering-mode/
COMMENT=	Emacs client for twitter
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/hayamiz/twittering-mode.git
GIT_MODULE.master=	twittering-mode
PKGSRC_SETENV+=		GIT_SSL_NO_VERIFY=true

WRKSRC=		${WRKDIR}/twittering-mode
NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../editors/emacs/modules.mk"
# Avoid single file spread out just under site-lisp directory.
# And directory name should get higher precedence, so begins with 'a'.
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/a-files

BUILD_DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

do-install:
	${INSTALL_DATA}   ${WRKSRC}/twittering-mode.el  ${DESTDIR}${INSTALLATION_DIRS}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
