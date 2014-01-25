# $NetBSD: Makefile,v 1.4 2014/01/25 10:38:23 thomasklausner Exp $

DISTNAME=	Wally-0.6.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Wally/wally/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://pypi.python.org/packages/source/W/Wally/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Wally/
COMMENT=	Tool for managing desktop backgrounds
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
