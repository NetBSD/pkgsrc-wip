# $NetBSD: Makefile,v 1.15 2009/07/30 13:04:02 mwdavies Exp $

DISTNAME=	kdenetwork-${_KDE_VERSION}
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

CONFLICTS=	kopete-[0-9]*

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

PKG_DESTDIR_SUPPORT=	user-destdir

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF

REPLACE_PERL+= \
	kopete/kopete/kconf_update/kopete-account-0.10.pl \
	kopete/kopete/kconf_update/kopete-gaim_to_pidgin_style.pl \
	kopete/kopete/kconf_update/kopete-initialstatus.pl \
	kopete/kopete/kconf_update/kopete-pluginloader.pl \
	kopete/kopete/kconf_update/kopete-update_yahoo_server.pl

REPLACE_SH+= \
	kopete/protocols/skype/call_end \
	kopete/protocols/skype/call_start \
	kopete/protocols/winpopup/winpopup-install.sh \
	kopete/protocols/winpopup/winpopup-send.sh

.include "../../wip/kde4/kde4.mk"

.include "../../chat/libmsn/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../chat/meanwhile/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../wip/ortp/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdelibs-experimental4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
