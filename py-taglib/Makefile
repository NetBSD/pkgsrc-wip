# $NetBSD: Makefile,v 1.1.1.1 2007/09/15 05:38:38 netcap Exp $
#

DISTNAME=	python-taglib-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/namingmuse/ \
		http://download2.berlios.de/namingmuse/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Python bindings for the taglib audio file tagging library

USE_TOOLS=	gmake
PYTHON_VERSIONS_ACCEPTED=       24 23 22
PY_PATCHPLIST=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
