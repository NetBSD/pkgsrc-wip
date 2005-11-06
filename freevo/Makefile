# $NetBSD: Makefile,v 1.12 2005/11/06 18:09:03 rillig Exp $
#

DISTNAME=		freevo-1.4.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-lookging digital video jukebox

DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PKG_SYSCONFSUBDIR=	freevo
CONF_FILES=		${PKG_SYSCONFDIR}/local_conf.py
PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		freevo
SUBST_STAGE.freevo=	post-patch
SUBST_FILES.freevo=	freevo
SUBST_SED.freevo+=	-e 's|@@PYTHONBIN@@|${PYTHONBIN}|g'
SUBST_SED.freevo+=	-e 's|@@PKGSRC_SYSCONF_DIR@@|${PKG_SYSCONFDIR}|g'

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example \
		${PKG_SYSCONFDIR}/local_conf.py

.include "../../devel/py-game/buildlink3.mk"
.include "../../wip/py-mmpython/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
