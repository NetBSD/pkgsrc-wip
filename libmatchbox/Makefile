# $NetBSD: Makefile,v 1.3 2004/03/20 17:12:34 xtraeme Exp $
#

DISTNAME=	libmatchbox-1.1
CATEGORIES=	devel
MASTER_SITES=	http://matchbox.handhelds.org/sources/libmatchbox/1.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/sources/libmatchbox/1.1/
COMMENT=	Library used by Matchbox Window Manager		

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=    ${WRKSRC}/libmb.pc.in

CONFIGURE_ARGS+=	--enable-jpeg

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
