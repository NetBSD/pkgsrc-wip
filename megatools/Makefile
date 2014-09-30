# $NetBSD: Makefile,v 1.2 2014/09/30 16:52:15 realzhtw Exp $

DISTNAME=	megatools-1.9.92
CATEGORIES=	filesystems security
MASTER_SITES=	http://megatools.megous.com/builds/

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://megatools.megous.com/builds/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libmega.pc.in

DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
