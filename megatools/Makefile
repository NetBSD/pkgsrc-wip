# $NetBSD: Makefile,v 1.4 2015/01/06 12:47:22 thomasklausner Exp $

DISTNAME=	megatools-1.9.94
CATEGORIES=	filesystems security
MASTER_SITES=	http://megatools.megous.com/builds/

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://megatools.megous.com/builds/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libmega.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
