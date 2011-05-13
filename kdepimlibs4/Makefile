# $NetBSD: Makefile,v 1.9 2011/05/13 23:25:16 mwdavies Exp $

DISTNAME=	kdepimlibs-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Support libraries for PIM for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDEPimLibsDependencies.cmake

REPLACE_PERL+= mailtransport/kconf_update/migrate-transports.pl

.include "../../wip/kde4/kde4.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/akonadi/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
