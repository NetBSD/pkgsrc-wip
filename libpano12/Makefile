# $NetBSD: Makefile,v 1.8 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=		libpano12-2.7.0.8
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=panotools/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://panotools.sourceforge.net/
COMMENT=		Panorama-tools is for making panoramic images from multiple pictures


MAKE_FILE=		makefile.netbsd
USE_JAVA=		yes
USE_PKGLOCALEDIR=	yes

post-extract:
	${CP} ${FILESDIR}/makefile.netbsd ${WRKSRC}/makefile.netbsd

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
