# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:44 othyro Exp $
#

DISTNAME=	ncl-2.1.18
PKGNAME=	lib${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ncl/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ncl.sourceforge.net/
COMMENT=	The NEXUS Class Library is a C++ library for parsing NEXUS files
LICENSE=	gnu-gpl-v2 AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	nclv2.1.pc.in

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
