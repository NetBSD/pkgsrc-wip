# $NetBSD$

DISTNAME=	qbe-0
PKGNAME=	qbe-git-0
CATEGORIES=	lang
GIT_REPO=	git://c9x.me/qbe.git
GIT_BRANCH=	master

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://c9x.me/compile/
COMMENT=	Compiler backend
LICENSE=	mit

CONFLICTS+=	qbe-[0-9]*

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

BUILD_TARGET=	qbe

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
