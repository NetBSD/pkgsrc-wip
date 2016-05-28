# $NetBSD: Makefile,v 1.15 2012/10/23 10:23:06 thomasklausner Exp $
#

DISTNAME=	ion-3-20090110
PKGNAME=	ion3-20090110
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://iki.fi/tuomov/dl/

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://tuomov.iki.fi/software/
COMMENT=	Tiling tabbed window manager


MAKE_JOBS_SAFE=		no

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

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Setting prefix paths.
SUBST_FILES.fix-paths=		system.mk
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
SUBST_CLASSES+=			remove-dl
SUBST_STAGE.remove-dl=		pre-configure
SUBST_MESSAGE.remove-dl=	Removing dl link.
SUBST_FILES.remove-dl=		system.mk
SUBST_SED.remove-dl=		-e 's,-ldl,,g'
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
