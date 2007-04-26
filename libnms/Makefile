# $NetBSD: Makefile,v 1.2 2007/04/26 12:45:39 netcap Exp $
#

DISTNAME=	libnms-0.6.0
CATEGORIES=	audio
MASTER_SITES=	http://streaming.polito.it/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://streaming.polito.it/client/library/
COMMENT=	Open Media Streaming Client Library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnms.pc.in

.include "../../mk/bsd.pkg.mk"
