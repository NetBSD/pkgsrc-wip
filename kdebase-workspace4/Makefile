# $NetBSD: Makefile,v 1.5 2007/12/23 01:53:02 mwdavies Exp $

DISTNAME=	kdebase-workspace-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	XXX for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

#REPLACE_BASH+= pics/oxygen/scalable/export_pngs.sh

#REPLACE_PERL+= \

RCD_SCRIPTS=		kdm

CONF_FILES=		${PREFIX}/share/kde/config/kdm/kdmrc \
			${PKG_SYSCONFDIR}/kdm/kdmrc
OWN_DIRS=		${PKG_SYSCONFDIR}/kdm

CONF_FILES+=		${PREFIX}/share/examples/kdebase-workspace4/ksysguarddrc \
			${PKG_SYSCONFDIR}/ksysguarddrc

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	kcontrol/kdm/main.cpp
SUBST_SED.paths=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
