# $NetBSD: Makefile,v 1.10 2009/01/07 01:44:00 lexort Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	Graphical tools for the KDE desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CHECK_PORTABILITY_SKIP+=ktimetracker/test/booktime-baddate.sh \
		ktimetracker/test/booktime-badduration.sh \
		ktimetracker/test/booktime-badtime.sh \
		ktimetracker/test/booktime-baduid.sh \
		ktimetracker/test/booktime-works.sh \
		ktimetracker/test/delete.sh \
		ktimetracker/test/refresh_on_change.sh \
		ktimetracker/test/version.sh

.include "../../wip/kde4/kde4.mk"

.include "../../devel/chmlib/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../wip/ebook-tools/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
