# $NetBSD: Makefile,v 1.1.1.1 2007/09/04 19:39:54 netcap Exp $
#

DISTNAME=	sonata-1.2.3
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/sonata/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://download.berlios.de/sonata/
COMMENT=	Elegant GTK2 client for the Music Player Daemon

PYTHON_VERSIONS_ACCEPTED=       24
PY_PATCHPLIST=  yes
PYDISTUTILSPKG= yes
USE_DIRS+=      xdg-1.4

DEPENDS+=	musicpd>0:../../audio/musicpd

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
