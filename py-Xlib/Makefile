# $NetBSD: Makefile,v 1.2 2004/07/18 15:12:53 ppostma Exp $

DISTNAME=	python-xlib-0.12
PKGNAME=	${PYPKGPREFIX}-Xlib-0.12
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-xlib/}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://python-xlib.sourceforge.net/
COMMENT=	Functional X client library for Python

USE_BUILDLINK3=	yes

PYDISTUTILSPKG= yes
PYBINMODULE=    yes
PYSETUP=        setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
