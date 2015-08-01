# $NetBSD: Makefile,v 1.1 2015/08/01 22:20:14 jihbed Exp $

DISTNAME=	verbiste-0.1.41
CATEGORIES=	textproc
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://perso.b2b2c.ca/sarrazip/dev/verbiste.html
COMMENT=	French verb conjugator/deconjugator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	verbiste-0.1.pc.in

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
