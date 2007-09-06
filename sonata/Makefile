# $NetBSD: Makefile,v 1.2 2007/09/06 22:26:43 thomasklausner Exp $
#

DISTNAME=	sonata-1.2.3
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/sonata/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://download.berlios.de/sonata/
COMMENT=	Elegant GTK2 client for the Music Player Daemon

DEPENDS+=	musicpd>0:../../audio/musicpd

PYTHON_VERSIONS_ACCEPTED=	24
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	pkg-config

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
