# $NetBSD$

DISTNAME=	qbe-1.0
CATEGORIES=	lang
MASTER_SITES=	https://c9x.me/git/qbe.git/snapshot/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://c9x.me/compile/
COMMENT=	Compiler backend
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

BUILD_TARGET=	qbe

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
