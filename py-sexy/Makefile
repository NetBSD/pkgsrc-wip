# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:29:08 jihbed Exp $
#

DISTNAME=	sexy-python-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	devel python
MASTER_SITES=	http://releases.chipx86.com/libsexy/sexy-python/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.chipx86.com/wiki/Libsexy
COMMENT=	Python bindings for libsexy
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES= c c++

BUILDLINK_PKGSRCDIR.libsexy?=	../../devel/libsexy
.include "../../devel/libsexy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
