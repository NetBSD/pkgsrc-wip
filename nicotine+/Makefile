# $NetBSD: Makefile,v 1.1.1.1 2006/12/19 20:14:00 netcap Exp $
#

DISTNAME=	nicotine+-1.2.6
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.nicotine-plus.org/files/tarballs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.nicotine-plus.org/
COMMENT=        Client for the SoulSeek, a peer-to-peer network for music

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=       24
PY_PATCHPLIST=  yes
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
