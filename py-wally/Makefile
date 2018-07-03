# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	Wally-0.6.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Wally/wally/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Wally/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Wally/
COMMENT=	Tool for managing desktop backgrounds
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
