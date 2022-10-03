# $NetBSD$

DISTNAME=	primesieve-8.0
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimwalisch/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimwalisch/primesieve/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	primesieve.pc.in

.include "../../mk/bsd.pkg.mk"
