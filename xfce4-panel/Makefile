# $NetBSD: Makefile,v 1.11 2007/01/23 08:00:38 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
#PKGREVISION=		1
CATEGORIES=		x11
COMMENT=		Xfce panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

# Compile the panel launcher without GCC optimization
# http://bugzilla.xfce.org/show_bug.cgi?id=2262
SUBST_CLASSES+=		launcher
SUBST_STAGE.launcher=	post-configure
SUBST_FILES.launcher=	plugins/launcher/Makefile
SUBST_SED.launcher=	-e 's|-O |-O0 |g'
SUBST_SED.launcher+=	-e 's|-O[123s] |-O0 |g'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
