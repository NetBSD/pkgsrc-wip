# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 16:04:40 xtraeme Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=        ${PYPKGPREFIX}-biggles-1.6.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT= 	Python module for creating 2D scientific plots

USE_X11=	yes
PYDISTUTILSPKG= yes
PYBINMODULE=	yes
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
