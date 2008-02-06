# $NetBSD: Makefile,v 1.3 2008/02/06 12:03:00 mwdavies Exp $

DISTNAME=	kdepimlibs-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Support libraries for PIM for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDEPimLibsDependencies.cmake

REPLACE_PERL+= mailtransport/kconf_update/migrate-transports.pl

.include "../../wip/kde4/kde4.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
