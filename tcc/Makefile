# $NetBSD: Makefile,v 1.9 2005/05/24 10:31:45 rillig Exp $
#

DISTNAME=	tcc-0.9.22
CATEGORIES=	lang
MASTER_SITES=	http://fabrice.bellard.free.fr/tcc/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.tinycc.org/
COMMENT=	The Smallest ANSI C compiler

ONLY_FOR_PLATFORM=      *-*-i386
NOT_FOR_PLATFORM=       NetBSD-1.6.2-*

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
SUBST_CLASSES=ldl
SUBST_FILES.ldl=Makefile
SUBST_STAGE.ldl=post-patch
SUBST_SED.ldl=-e 's,LIBS=,\#LIBS,'
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
