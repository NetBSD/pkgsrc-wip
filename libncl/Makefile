# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=	ncl-2.1.18
PKGNAME=lib${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/ncl/NCL/ncl-2.1.18/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ncl.sourceforge.net/
COMMENT=	The NEXUS Class Library is a C++ library for parsing NEXUS files
LICENSE=	gnu-gpl-v2 AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL= yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	nclv2.1.pc.in

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
