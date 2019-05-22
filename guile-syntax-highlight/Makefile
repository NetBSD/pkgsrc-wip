# $NetBSD$

DISTNAME=	guile-syntax-highlight-0.1
CATEGORIES=	textproc
MASTER_SITES=	https://files.dthompson.us/guile-syntax-highlight/

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://dthompson.us/projects/guile-syntax-highlight.html
COMMENT=	General-purpose syntax highlighting library for GNU Guile
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib
USE_TOOLS+=		pkg-config

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
