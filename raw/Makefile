# $NetBSD$
VERSION=	0.1.1
#PKGNAME=	raw-${VERSION}
CATEGORIES=	games
GHCOMMIT=	d25fa27040834764f3e767ec04906e171002e02f
GITHUB_TAG=	${GHCOMMIT}
DISTNAME=	Another-World-Bytecode-Interpreter

MASTER_SITES=	${MASTER_SITE_GITHUB:=fabiensanglard/}
EXTRACT_SUFX=	.zip
#LICENSE=	#

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://fabiensanglard.net/anotherWorld_code_review/index.php/
COMMENT=	Open Source implementation of Another World engine

DIST_SUBDIR=	Another-World-Bytecode-Interpreter
WRKSRC=		${WRKDIR}/Another-World-Bytecode-Interpreter-${GHCOMMIT}
BUILD_TARGET=	game

USE_LANGUAGES+=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
