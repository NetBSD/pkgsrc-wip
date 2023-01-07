# $NetBSD$

DISTNAME=	cmoc-0.1.80
CATEGORIES=	cross
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html
COMMENT=	6809-generating cross-compiler for a large subset of the C language
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake perl

CFLAGS.NetBSD+=		-D__unix
CXXFLAGS.NetBSD+=	-D__unix

.include "../../wip/lwtools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
