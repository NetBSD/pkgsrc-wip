# $NetBSD$

GITHUB_PROJECT=	libppd
DISTNAME=	libppd-2.0.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_RELEASE=	2.0.0

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/libppd/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libppd.pc.in

.include "../../wip/libcupsfilters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
