# $NetBSD: Makefile,v 1.18 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=		fluxspace-0.0.3
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fluxspace/}
LICENSE=		gnu-gpl-v3

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

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-xml

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
