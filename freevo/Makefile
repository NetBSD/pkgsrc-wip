# $NetBSD: Makefile,v 1.9 2004/05/10 01:49:05 blef Exp $
#

DISTNAME=		freevo-1.4.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-lookging digital video jukebox

DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PKG_SYSCONFSUBDIR=	freevo
CONF_FILES=		${PKG_SYSCONFDIR}/local_conf.py
PLIST_SUBST=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

# well, this could be propably done better way I can't think of
# 	-- dotz@irc.pl

post-patch:
	${CP} ${WRKSRC}/freevo ${WRKSRC}/freevo.pre
	sed -e 's|@@PYTHONBIN@@|${PYTHONBIN}|g' < ${WRKSRC}/freevo.pre > \
		${WRKSRC}/freevo
	${CP} ${WRKSRC}/freevo ${WRKSRC}/freevo.pre
	sed -e 's|@@PKGSRC_SYSCONF_DIR@@|${PKG_SYSCONFDIR}|g' < ${WRKSRC}/freevo.pre > \
		${WRKSRC}/freevo

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example \
		${PKG_SYSCONFDIR}/local_conf.py

.include "../../wip/py-game/buildlink3.mk"
.include "../../wip/py-mmpython/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
