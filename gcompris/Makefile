# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 05:59:29 jeremy-c-reed Exp $

DISTNAME=	gcompris-3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ofset.sourceforge.net/gcompris/
COMMENT=	Educational games for children

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_TOOLS+=		tar

.include "../../converters/libiconv/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
