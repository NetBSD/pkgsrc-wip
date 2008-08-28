# $NetBSD: Makefile,v 1.1.1.1 2008/08/28 21:34:40 thomasklausner Exp $
#

DISTNAME=	digikam-0.10.0-beta2
PKGNAME=	digikam-0.10.0beta2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://digikam.sourceforge.net/
COMMENT=	Advanced digital photo management application (KDE4)

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

BUILD_DEPENDS+=	automoc4>=0.9.83:../../wip/automoc4

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt pkg-config

.include "options.mk"

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
.include "../../wip/kdegraphics4/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
