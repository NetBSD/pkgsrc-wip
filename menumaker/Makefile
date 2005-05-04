# $NetBSD: Makefile,v 1.3 2005/05/04 01:06:06 jeremy-c-reed Exp $
#

DISTNAME=		MenuMaker-0.17
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=menumaker/}

MAINTAINER=		low@ameba6.com
HOMEPAGE=		http://menumaker.sourceforge.net/
COMMENT=		Generates menus for X Window managers by scanning for installed programs

PYDISTUTILSPKG=		yes
PYBINMODULE=    	yes
PYSETUPOPTARGS?=       
PY_PATCHPLIST=          yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
