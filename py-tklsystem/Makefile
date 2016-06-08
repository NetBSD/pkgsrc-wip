# $NetBSD: Makefile,v 1.1 2014/07/26 13:29:59 jihbed Exp $

DISTNAME=	TkLsystem-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=T/TkLsystem/}
EXTRACT_SUFX=	.zip#md5=af56cdc95cda767a7fdbf66db27c278e

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/yasar11732/tklsystem
COMMENT=	Tkinter interface to work with L-System equations
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-liblzma>=0.5.3:../../wip/py-liblzma

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
#.include "../../wip/py-lzma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
