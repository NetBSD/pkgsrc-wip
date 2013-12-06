# $NetBSD: Makefile,v 1.2 2013/12/06 11:31:35 noud4 Exp $

DISTNAME=	libindicator-12.10.1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/libindicator/12.10/12.10.1/+download/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libindicator
COMMENT=	Symbols and convience functions that all indicators would like to use
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM=	rm:-Werror
PKGCONFIG_OVERRIDE=	libindicator/indicator3-0.4.pc.in.in
PKGCONFIG_OVERRIDE+=	libindicator/indicator-0.4.pc.in.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
