# $NetBSD: Makefile,v 1.3 2011/02/12 20:46:05 ryo-on Exp $
#

DISTNAME=	zim-0.49
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	http://zim-wiki.org/downloads/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://zim-wiki.org/
COMMENT=	Zim brings the concept of a wiki to your desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	26 25
REPLACE_PYTHON=	${WRKSRC}/zim.py
PYDISTUTILSPKG=	YES

DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION_DEFAULT} == "25"
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
