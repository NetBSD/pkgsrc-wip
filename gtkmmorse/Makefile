# $NetBSD$

DISTNAME=	gtkmmorse-0.9.27
CATEGORIES=	ham
MASTER_SITES=	http://savannah.nongnu.org/download/gtkmmorse/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/gtkmmorse/
COMMENT=	Morse Code Trainer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/gconfmm/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
