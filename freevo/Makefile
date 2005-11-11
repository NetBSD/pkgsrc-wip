# $NetBSD: Makefile,v 1.13 2005/11/11 06:34:53 dhowland Exp $
#

DISTNAME=		freevo-1.5.3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-lookging digital video jukebox

DEPENDS+=		mplayer>=1.0rc7:../../multimedia/mplayer
DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	freevo
EGDIR=			${PREFIX}/share/examples/freevo
CONF_FILES=		${EGDIR}/local_conf.py.example		\
			${PKG_SYSCONFDIR}/local_conf.py

SUBST_CLASSES+=		freevo
SUBST_STAGE.freevo=	post-patch
SUBST_FILES.freevo=	src/config.py
SUBST_SED.freevo+=	-e 's|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/freevo
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example \
		${PREFIX}/share/examples/freevo/local_conf.py.example

.include "../../devel/py-game/buildlink3.mk"
.include "../../wip/py-mmpython/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
