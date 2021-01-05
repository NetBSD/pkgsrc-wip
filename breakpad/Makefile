# $NetBSD$

PKGNAME=	breakpad-64
GIT_REPO=	https://chromium.googlesource.com/breakpad/breakpad.git
CATEGORIES=	misc
GIT_REVISION=	f469cab97b56b79107ce943e13b375add2676d17

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://chromium.googlesource.com/breakpad/breakpad
COMMENT=	Client and server components for a crash reporting system
LICENSE=	modified-bsd AND unicode

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++11

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
