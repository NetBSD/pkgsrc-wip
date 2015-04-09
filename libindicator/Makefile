# $NetBSD: Makefile,v 1.7 2015/04/09 13:16:09 krytarowski Exp $

DISTNAME=	libindicator-12.10.1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/libindicator/12.10/12.10.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libindicator
COMMENT=	Symbols and convience functions that all indicators would like to use
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

EXTRACT_USING=	gtar

BUILDLINK_TRANSFORM+=	rm:-Werror
PKGCONFIG_OVERRIDE=	libindicator/indicator3-0.4.pc.in.in
PKGCONFIG_OVERRIDE+=	libindicator/indicator-0.4.pc.in.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
