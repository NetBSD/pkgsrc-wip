# $NetBSD: Makefile,v 1.2 2006/07/08 11:40:08 shattered Exp $
#

DISTNAME=		quodlibet-0.22
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://www.sacredchao.net/~piman/software/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.sacredchao.net/quodlibet/wiki
COMMENT=		Finally a good alternative to iTunes

DEPENDS+=		${PYPKGPREFIX}-mutagen>=1.5:../../wip/mutagen
DEPENDS+=		${PYPKGPREFIX}-gst-python>=0.10.0:../../wip/gst-python
DEPENDS+=		gst-plugins0.10-mad>=0.10.0:../../audio/gst-plugins0.10-mad
DEPENDS+=		gst-plugins0.10-vorbis>=0.10.0:../../audio/gst-plugins0.10-vorbis
DEPENDS+=		gst-plugins0.10-ogg>=0.10.0:../../multimedia/gst-plugins0.10-ogg

PYTHON_VERSIONS_ACCEPTED=	24 25
PYTHON_PATCH_SCRIPTS=	*.py
NO_BUILD=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
