# $NetBSD: Makefile,v 1.1.1.1 2004/07/13 01:46:47 cetrox Exp $

DISTNAME=	python-xlib-0.12
PKGNAME=	${PYPKGPREFIX}-Xlib-0.12
CATEGORIES=	wip
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
