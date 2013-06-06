# $NetBSD: Makefile,v 1.5 2013/06/06 01:21:22 makoto Exp $

DISTNAME=	twittering-mode-3.0.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hayamiz/twittering-mode/
COMMENT=	Emacs client for twitter
LICENSE=	gnu-gpl-v2

MASTER_SITES+=	http://sourceforge.net/projects/twmode/files/twittering-mode-3.0.0/

NO_BUILD=	yes
USE_LANGUAGES=	# none
TEST_TARGET=	check

.include "../../editors/emacs/modules.mk"
# Avoid single file spread out just under site-lisp directory.
# And directory name should get higher precedence, so begins with 'a'.
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/a-files

do-install:
	${INSTALL_DATA}   ${WRKSRC}/twittering-mode.el  ${DESTDIR}${INSTALLATION_DIRS}

.include "../../mk/bsd.pkg.mk"
