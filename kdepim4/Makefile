# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 04:10:15 mwdavies Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../wip/kde4/Makefile.kde4"

BUILD_MAKE_FLAGS+= VERBOSE=1

CHECK_PORTABILITY_SKIP+=ktimetracker/test/booktime-baddate.sh \
		ktimetracker/test/booktime-badduration.sh \
		ktimetracker/test/booktime-badtime.sh \
		ktimetracker/test/booktime-baduid.sh \
		ktimetracker/test/booktime-works.sh \
		ktimetracker/test/delete.sh \
		ktimetracker/test/refresh_on_change.sh \
		ktimetracker/test/version.sh

.include "../../wip/kde4/kde4.mk"

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/libopensync/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
