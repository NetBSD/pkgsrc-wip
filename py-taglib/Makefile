# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	python-taglib-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/namingmuse/ \
		http://download2.berlios.de/namingmuse/
LICENSE=	gnu-lgpl-v3 AND mpl-1.1

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://developer.kde.org/~wheeler/taglib.html
COMMENT=	Python bindings for the taglib audio file tagging library

USE_TOOLS=	gmake
PY_PATCHPLIST=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
