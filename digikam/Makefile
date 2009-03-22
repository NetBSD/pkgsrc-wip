# $NetBSD: Makefile,v 1.7 2009/03/22 19:18:29 thomasklausner Exp $
#

DISTNAME=	digikam-0.10.0-beta5
PKGNAME=	digikam-0.10.0beta5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://digikam.sourceforge.net/
COMMENT=	Advanced digital photo management application (KDE4)

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

REPLACE_PERL=	utilities/scripts/digitaglinktree
USE_CMAKE=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gawk msgfmt perl:run pkg-config

.include "options.mk"

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for libkdcraw>=0.4.0
BUILDLINK_API_DEPENDS.kdegraphics4+=	kdegraphics4>=4.1.2nb1
.include "../../wip/kdegraphics4/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
