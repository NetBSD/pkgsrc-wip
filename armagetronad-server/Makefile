# $NetBSD: Makefile,v 1.3 2010/12/26 05:01:21 davesainty Exp $
#

.include "../../wip/armagetronad/Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/armagetronad/armagetronad-server/}
COMMENT=	Server for the armagetronad game

MAINTAINER=     pkgsrc-users@NetBSD.org

# Enable server, don't build client
CONFIGURE_ARGS+=	--enable-dedicated

# pkgsrc specific handling of configuration
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=    sysconfdir=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/armagetronad-dedicated
MAKE_DIRS+=	${PKG_SYSCONFDIR}/armagetronad-dedicated/examples
MAKE_DIRS+=	${PKG_SYSCONFDIR}/armagetronad-dedicated/examples/cvs_test

.for f in aiplayers.cfg default.cfg master.srv rc.config settings.cfg settings_authentication.cfg settings_dedicated.cfg settings_visual.cfg subcultures.srv
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/${f} ${PKG_SYSCONFDIR}/${PKGBASE}/${f}
.endfor

.for f in breakfast_in_hell.cfg death_zone.cfg fortress_soccer.cfg single_use_turbo.cfg teamsumo.cfg
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/examples/${f} ${PKG_SYSCONFDIR}/${PKGBASE}/examples/${f}
.endfor

.for f in fortress_complete.cfg fortress_physics.cfg fortress_politics.cfg fortress_scoring.cfg sumo_complete.cfg
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/examples/cvs_test/${f} ${PKG_SYSCONFDIR}/${PKGBASE}/examples/cvs_test/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
