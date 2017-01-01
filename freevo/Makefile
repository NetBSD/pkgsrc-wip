# $NetBSD: Makefile,v 1.43 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=		freevo-1.7.6
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-looking digital video jukebox

DEPENDS+=		aumix>=2.8:../../audio/aumix
DEPENDS+=		mplayer>=1.0rc7:../../multimedia/mplayer
DEPENDS+=		${PYPKGPREFIX}-sqlite>=1.0.1:../../databases/py-sqlite
DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../net/py-twisted
#DEPENDS+=		${PYPKGPREFIX}-twisted-web>=0.5.0:../../wip/py-twisted-web
DEPENDS+=		${PYPKGPREFIX}-elementtree-[0-9]*:../../textproc/py-elementtree
DEPENDS+=		${PYPKGPREFIX}-beautifulsoup-[0-9]*:../../www/py-beautifulsoup


PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-beautifulsoup, py-mxDateTime, py-imaging, py-twisted, py-elementtree, py-xml
USE_PKGLOCALEDIR=	yes

CHECK_PORTABILITY_SKIP+=	boot/freevo
CHECK_PORTABILITY_SKIP+=	contrib/suse/freevo.daily
CHECK_PORTABILITY_SKIP+=	contrib/suse/freevo.init

.include "options.mk"

PKG_SYSCONFSUBDIR=	freevo
EGDIR=			${PREFIX}/share/examples/freevo
CONF_FILES=		${EGDIR}/local_conf.py.example		\
			${PKG_SYSCONFDIR}/local_conf.py

SUBST_CLASSES+=		freevo
SUBST_STAGE.freevo=	pre-configure
SUBST_FILES.freevo=	src/config.py
SUBST_SED.freevo+=	-e 's|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g'

post-patch:
	${CP} ${FILESDIR}/pygamejoy.py ${WRKSRC}/src/plugins/pygamejoy.py

post-install:
	${RM} ${PREFIX}/share/freevo/contrib/fbcon/mgafb.orig
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/freevo
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example \
		${PREFIX}/share/examples/freevo/local_conf.py.example

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../multimedia/libdvdcss/buildlink3.mk"  # not default by libdvdread
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../wip/py-kaa-imlib2/buildlink3.mk"
.include "../../wip/py-kaa-metadata/buildlink3.mk"
.include "../../wip/py-osd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
