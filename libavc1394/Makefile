# $NetBSD: Makefile,v 1.2 2004/08/17 18:29:48 tvierling Exp $
#

DISTNAME=		libavc1394-0.4.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libavc1394/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://sourceforge.net/projects/libavc1394/
COMMENT=		Interface for the 1394 Audio/Video Controls

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libavc1394.la
LIBTOOL_LA_FILES+=	lib/librom1394.la
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../wip/libraw1394/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
