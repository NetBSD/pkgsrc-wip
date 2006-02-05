# $NetBSD: Makefile,v 1.1.1.1 2006/02/05 01:43:40 shattered Exp $
#

DISTNAME=		quodlibet-0.14
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://www.sacredchao.net/~piman/software/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.sacredchao.net/quodlibet
COMMENT=		Finally a good alternative to iTunes

DEPENDS+=		${PYPKGPREFIX}-gst-python>=0.0:../../wip/gst-python
DEPENDS+=		${PYPKGPREFIX}-vorbis>=0.0:../../audio/py-vorbis
DEPENDS+=		${PYPKGPREFIX}-mad>=0.0:../../audio/py-mad

PYTHON_PATCH_SCRIPTS=	*.py
NO_BUILD=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
