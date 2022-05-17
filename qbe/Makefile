# $NetBSD$

DISTNAME=	qbe-0
CATEGORIES=	lang
GIT_REPO=	git://c9x.me/qbe.git
GIT_BRANCH=	master
GIT_REVISION=	2caa26e388b1c904d2f12fb09f84df7e761d8331

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://c9x.me/compile/
COMMENT=	QBE compiler backend
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

BUILD_TARGET=	obj/qbe

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
