# $NetBSD: Makefile,v 1.9 2015/05/30 01:49:33 krytarowski Exp $

.include "../../wip/liblxqt/Makefile.common"

DISTNAME=	lxqt-panel-0.9.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Desktop panel
LICENSE=	gnu-lgpl-v2.1

EGDIR=		${PREFIX}/share/examples/lxqt-panel

OWN_DIRS=	${PKG_SYSCONFDIR}/xdg/lxqt

CONF_FILES+=	${EGDIR}/xdg/lxqt/panel.conf ${PKG_SYSCONFDIR}/xdg/lxqt/panel.conf

SUBST_CLASSES+=		confdir
SUBST_FILES.confdir=	panel/CMakeLists.txt
SUBST_SED.confdir=	-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.confdir=	post-patch

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libsysstat/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
