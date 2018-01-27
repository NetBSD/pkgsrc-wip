# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	pigg-0.2.0
PKGNAME=	${PYPKGPREFIX}-logilab-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	http://ftp.logilab.org/pub/pigg/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/pigg
COMMENT=	Python Interface Generator for Gtk implementation of the MVC pattern
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
