# $NetBSD: Makefile,v 1.2 2004/01/25 02:12:11 grantbeattie Exp $
#

DISTNAME=		fluxspace-0.0.3
CATEGORIES=		x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxspace/}

MAINTAINER=		poff@sixbit.org
COMMENT=		Fluxbox workspace manager, environment

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# Ensure we export symbols in the linked shared object.
LDFLAGS+=       ${EXPORT_SYMBOLS_LDFLAGS}

CONFIGURE_ENV+= PYTHON="${LOCALBASE}/bin/python2.2"
CONFIGURE_ENV+= PYTHON_LDFLAGS="${BUILDLINK_LDFLAGS.python22}"

.include "../../textproc/pyxml/buildlink2.mk"
.include "../../devel/swig/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../lang/python22/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
