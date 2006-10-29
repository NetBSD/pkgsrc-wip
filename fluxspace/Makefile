# $NetBSD: Makefile,v 1.13 2006/10/29 08:32:43 shattered Exp $
#

DISTNAME=		fluxspace-0.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fluxspace/}

MAINTAINER=		poff@sixbit.org
HOMEPAGE=		http://fluxspace.sourceforge.net/
COMMENT=		Fluxbox workspace manager, environment

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PY_PATCHPLIST=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

CONFIGURE_ENV+= PYTHON=${PYTHONBIN:Q}

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
