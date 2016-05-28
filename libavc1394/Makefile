# $NetBSD: Makefile,v 1.5 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=		libavc1394-0.4.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libavc1394/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://sourceforge.net/projects/libavc1394/
COMMENT=		Interface for the 1394 Audio/Video Controls


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../wip/libraw1394/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
