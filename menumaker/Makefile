# $NetBSD: Makefile,v 1.5 2006/10/29 08:32:47 shattered Exp $
#

DISTNAME=		MenuMaker-0.17
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=menumaker/}

MAINTAINER=		low@ameba6.com
HOMEPAGE=		http://menumaker.sourceforge.net/
COMMENT=		Generates menus for X Window managers by scanning for installed programs

PYDISTUTILSPKG=		yes
PYBINMODULE=	yes
PYSETUPOPTARGS?=
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
