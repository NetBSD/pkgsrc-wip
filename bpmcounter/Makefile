# $NetBSD: Makefile,v 1.4 2012/10/31 12:13:14 othyro Exp $
#

DISTNAME=	bpmcounter-0.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djplay/bpmcounter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://djplay.sourceforge.net/
COMMENT=	Comfortable GUI application to count and tag MP3 file collection
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake pkg-config

.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
