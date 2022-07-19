# $NetBSD$

DISTNAME=	sjson-0.2.2
PKGNAME=	guile-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://dustycloud.org/misc/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://gitlab.com/dustyweb/guile-sjson
COMMENT=	JSON reader/writer for guile
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

TEST_TARGET=	check

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
