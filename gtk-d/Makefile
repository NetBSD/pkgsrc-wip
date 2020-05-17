# $NetBSD$

DISTNAME=	GtkD-3.9.0
CATEGORIES=	x11
MASTER_SITES=	https://gtkd.org/Downloads/sources/
EXTRACT_SUFX=	.zip

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://gtkd.org/Downloads/sources/
COMMENT=	GtkD is a D binding and OO wrapper of GTK+
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c # ldc uses the C compiler for linking

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

BUILD_MAKE_FLAGS+=LDFLAGS=-L=${LDFLAGS}

MAKE_ENV+=	prefix=${PREFIX}

BUILD_DEPENDS+=	ldc>1.0:../../wip/ldc

.include "../../mk/bsd.pkg.mk"
