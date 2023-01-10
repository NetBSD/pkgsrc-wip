# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	blink-0.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/jart/blink.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jart/blink
COMMENT=	Tiniest x86-64-linux emulator
LICENSE=	isc

USE_LANGUAGES=	c11
USE_TOOLS+=	gmake
BUILD_TARGET=	o
TEST_TARGET=	check

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRSRKC}/o/blink/blink ${DESTDIR}${PREFIX}/bin

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
