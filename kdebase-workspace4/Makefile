# $NetBSD: Makefile,v 1.2 2007/12/12 10:20:13 mwdavies Exp $

DISTNAME=	kdebase-workspace-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	XXX for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

BUILD_MAKE_FLAGS+= VERBOSE=1

#REPLACE_BASH+= pics/oxygen/scalable/export_pngs.sh

#REPLACE_PERL+= \

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
