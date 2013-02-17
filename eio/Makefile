# $NetBSD: Makefile,v 1.2 2013/02/17 13:11:06 roelants Exp $
#

DISTNAME=	eio-1.7.5
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://download.enlightenment.org/releases/
COMMENT=	Asynchronous I/O library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	eio.pc.in

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
