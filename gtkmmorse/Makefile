# $NetBSD$

DISTNAME=	gtkmmorse-0.9.27
CATEGORIES=	ham
MASTER_SITES=	http://savannah.nongnu.org/download/gtkmmorse/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/gtkmmorse/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# url2pkg-marker (please do not remove this line.)
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
