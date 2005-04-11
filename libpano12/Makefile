# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:48 tvierling Exp $
#

DISTNAME=		libpano12-2.7.0.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=panotools/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://panotools.sourceforge.net/
COMMENT=		Panorama-tools is for making panoramic images from multiple pictures

MAKEFILE=		makefile.netbsd
USE_JAVA=		YES
USE_PKGLOCALEDIR=	yes

post-extract:
	${CP} ${FILESDIR}/makefile.netbsd ${WRKSRC}/makefile.netbsd

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
