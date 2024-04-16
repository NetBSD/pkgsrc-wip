# $NetBSD$

GITHUB_PROJECT=	libppd
DISTNAME=	libppd-2.0.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_RELEASE=	2.0.0

MAINTAINER=	use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/libppd/
COMMENT=	PostScript Printer Descriptions library
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-mutool

PKGCONFIG_OVERRIDE+=	libppd.pc.in

.include "../../wip/libcupsfilters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
