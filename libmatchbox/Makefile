# $NetBSD: Makefile,v 1.9 2005/01/01 22:23:14 mattd Exp $
#

DISTNAME=	libmatchbox-1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.handhelds.org/projects/matchbox/sources/libmatchbox/1.4/
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
