# $NetBSD: Makefile,v 1.4 2008/01/07 20:37:08 pmatias Exp $
#

DISTNAME=	ion-3rc-20080103
PKGNAME=	ion3-20080103
CATEGORIES=	wm x11
MASTER_SITES=	http://iki.fi/tuomov/dl/

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://modeemi.fi/~tuomov/ion/
COMMENT=	Tiling tabbed window manager

USE_TOOLS+=	gmake msgfmt

EGDIR=		${PREFIX}/share/examples/ion3
EGFILES=	cfg_defaults.lua  cfg_layouts.lua  cfg_statusbar.lua    \
		look_cleanviolet.lua  look_greyviolet.lua  cfg_dock.lua \
		cfg_menu.lua  cfg_tiling.lua  lookcommon_clean.lua      \
		look_ios.lua  cfg_ioncore.lua  cfg_pwm.lua              \
		look_brownsteel.lua  lookcommon_emboss.lua  look.lua    \
		cfg_ion.lua  cfg_query.lua  look_cleanios.lua           \
		look_dusky.lua  look_newviolet.lua  cfg_kludges.lua     \
		cfg_sp.lua  look_clean.lua  look_greenlight.lua         \
		look_simpleblue.lua

PKG_SYSCONFSUBDIR=	ion3

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

SUBST_CLASSES+=                 fix-paths
SUBST_STAGE.fix-paths=          pre-configure
SUBST_MESSAGE.fix-paths=        Setting prefix paths.
SUBST_FILES.fix-paths=          system.mk
SUBST_SED.fix-paths=            -e 's,@PREFIX@,${PREFIX},g'


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
