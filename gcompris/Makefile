# $NetBSD: Makefile,v 1.2 2004/01/25 02:12:38 grantbeattie Exp $

DISTNAME=	gcompris-3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ofset.sourceforge.net/gcompris/
COMMENT=	Educational games for children

USE_GNU_TOOLS+=		make
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
