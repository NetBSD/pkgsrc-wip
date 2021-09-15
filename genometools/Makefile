# $NetBSD$

DISTNAME=	genometools-1.6.2
CATEGORIES=	biology
MASTER_SITES=	http://genometools.org/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://genometools.org/pub/
COMMENT=	Collection of bioinformatics tools
LICENSE=	isc # + others for specific external tools

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c
# MAKE_ENV+=	useshared=yes	# include system libraries, but need dependencies
INSTALL_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OS} == Darwin
pre-install:
	install_name_tool -id ${PREFIX}/lib/libgenometools.dylib ${WRKSRC}/lib/libgenometools.dylib
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
