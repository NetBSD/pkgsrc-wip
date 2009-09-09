# $NetBSD: Makefile,v 1.4 2009/09/09 11:18:58 thomasklausner Exp $
#

DISTNAME=	python-taglib-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/namingmuse/ \
		http://download2.berlios.de/namingmuse/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Python bindings for the taglib audio file tagging library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS=	gmake
PY_PATCHPLIST=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
