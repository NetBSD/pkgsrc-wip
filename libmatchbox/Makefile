# $NetBSD: Makefile,v 1.6 2004/06/07 23:59:42 xtraeme Exp $
#

DISTNAME=	libmatchbox-1.2
CATEGORIES=	devel
MASTER_SITES=	http://matchbox.handhelds.org/sources/libmatchbox/1.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Library used by Matchbox

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	libmb.pc.in

CONFIGURE_ARGS+=	--enable-jpeg

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
