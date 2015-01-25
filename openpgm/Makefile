# $NetBSD: Makefile,v 1.1 2015/01/25 09:13:35 obache Exp $
#

DISTNAME=	libpgm-5.2.122
PKGNAME=	${DISTNAME:S/lib/open/}
CATEGORIES=	net
MASTER_SITES=	http://openpgm.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/openpgm/
COMMENT=	Open source implementation of the Pragmatic General Multicast
LICENSE=	gnu-lgpl-v2.1 # or later

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	openpgm/pgm/openpgm-5.2.pc.in

CONFIGURE_DIRS=		openpgm/pgm

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_func_getprotobyname_r=no
.endif

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
