# $NetBSD: Makefile,v 1.1 2014/07/28 18:43:34 jihbed Exp $

DISTNAME=	modglue-1.19
CATEGORIES=	math
MASTER_SITES=	http://cadabra.phi-sci.com/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cadabra.phi-sci.com/
COMMENT=	C++ library for handling co-processes
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=		modglue-1.19/modglue.pc.in
CHECK_PORTABILITY_SKIP+=	configure


.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
