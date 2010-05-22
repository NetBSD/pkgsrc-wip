# $NetBSD: Makefile,v 1.1.1.1 2010/05/22 23:09:54 jihbed Exp $
#

DISTNAME=	Wally-0.6.14.tar
EGG_NAME=	Wally-0.6.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Wally/wally/S/.tar//}
CATEGORIES=	sysutils
MASTER_SITES=	http://pypi.python.org/packages/source/W/Wally/
EXTRACT_SUFX=	.gz#md5=43820ab951aefb8ed82e4a3238c0eaa1

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Wally/
COMMENT=	Tool for managing desktop backgrounds
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Wally-0.6.14
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
