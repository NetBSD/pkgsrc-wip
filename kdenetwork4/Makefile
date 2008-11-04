# $NetBSD: Makefile,v 1.11 2008/11/04 10:21:49 mwdavies Exp $

DISTNAME=	kdenetwork-${_KDE_VERSION}
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

CONFLICTS=	kopete-[0-9]*

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF

REPLACE_PERL+= \
	kopete/kopete/kconf_update/kopete-account-0.10.pl \
	kopete/kopete/kconf_update/kopete-pluginloader.pl

.include "../../wip/kde4/kde4.mk"

.include "../../chat/libotr/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
