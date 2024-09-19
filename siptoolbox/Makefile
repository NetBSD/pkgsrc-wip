# $NetBSD: Makefile,v 1.5 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=	sip-0.4.0-rc1
PKGNAME=	siptoolbox-0.4.0nb1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=siptoolbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://siptoolbox.sourceforge.net/
COMMENT=	Scilab Image Processing toolbox
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PLIST_SUBST+=		SCIVERSION=${SCIVERSION:Q}

.include "../../math/scilab/buildlink3.mk"
.include "../../wip/libanimal/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
