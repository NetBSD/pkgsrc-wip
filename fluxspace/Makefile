# $NetBSD: Makefile,v 1.5 2004/05/05 03:04:45 blef Exp $
#

DISTNAME=		fluxspace-0.0.3
CATEGORIES=		x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxspace/}

MAINTAINER=		poff@sixbit.org
COMMENT=		Fluxbox workspace manager, environment

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=       ${EXPORT_SYMBOLS_LDFLAGS}

CONFIGURE_ENV+= PYTHON="${LOCALBASE}/bin/python2.2"
CONFIGURE_ENV+= PYTHON_LDFLAGS="${BUILDLINK_LDFLAGS.python22}"

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
