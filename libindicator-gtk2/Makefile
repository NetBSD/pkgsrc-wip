# $NetBSD: Makefile,v 1.1 2015/01/01 07:52:39 obache Exp $

DISTNAME=	libindicator-12.10.1
PKGNAME=	${DISTNAME:S/-/-gtk2-/}
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/libindicator/12.10/12.10.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libindicator
COMMENT=	Symbols and convience functions that all indicators would like to use (Gtk2)
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE=	libindicator/indicator3-0.4.pc.in.in
PKGCONFIG_OVERRIDE+=	libindicator/indicator-0.4.pc.in.in

CONFIGURE_ARGS+=	--with-gtk=2

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
