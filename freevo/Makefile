# $NetBSD: Makefile,v 1.26 2006/07/11 02:54:40 dhowland Exp $
#

DISTNAME=		freevo-1.5.4
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-looking digital video jukebox

DEPENDS+=		aumix>=2.8:../../audio/aumix
DEPENDS+=		mplayer>=1.0rc7:../../multimedia/mplayer
DEPENDS+=		${PYPKGPREFIX}-sqlite>=1.0.1:../../databases/py-sqlite
DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-web>=0.5.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes
USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "options.mk"

PKG_SYSCONFSUBDIR=	freevo
EGDIR=			${PREFIX}/share/examples/freevo
CONF_FILES=		${EGDIR}/local_conf.py.example		\
			${PKG_SYSCONFDIR}/local_conf.py

SUBST_CLASSES+=		freevo
SUBST_STAGE.freevo=	post-patch
SUBST_FILES.freevo=	src/config.py
SUBST_SED.freevo+=	-e 's|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g'

post-patch:
	${CP} ${FILESDIR}/pygamejoy.py ${WRKSRC}/src/plugins/pygamejoy.py

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/freevo
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example \
		${PREFIX}/share/examples/freevo/local_conf.py.example

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../multimedia/libdvdcss/buildlink3.mk"  # not default by libdvdread
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../wip/py-mmpython/buildlink3.mk"
.include "../../wip/py-osd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
