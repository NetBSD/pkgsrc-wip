# $NetBSD: Makefile,v 1.2 2008/01/18 04:30:15 tnn2 Exp $

DISTNAME=	kdepimlibs-${_KDE_VERSION}
PKGREVISION=	1
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
