# $NetBSD$

DISTNAME=	sblim-sfcc-2.2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sblim/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/sblim/
COMMENT=	Small Footprint CIM Client Library
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/dlopen.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
