# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 11:03:50 mpasternak Exp $
#

DISTNAME=		freevo-1.4.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://freevo.sourceforge.net/
COMMENT=		Fancy-lookging digital video jukebox

DEPENDS+=		mplayer>=1.0rc3:../../graphics/mplayer

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../wip/py-game/buildlink2.mk"
.include "../../wip/py-twisted/buildlink2.mk"
.include "../../wip/py-mmpython/buildlink2.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
