# $NetBSD: Makefile,v 1.2 2006/08/14 00:02:30 splitscreen Exp $
#

DISTNAME=		pydb-1.17
CATEGORIES=		python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bashdb/}

MAINTAINER=		splitscreen@users.sourceforge.net
HOMEPAGE=		http://easynews.dl.sourceforge.net/sourceforge/bashdb/
COMMENT=		The Extended Python Debugger

USE_TOOLS+=		gmake

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=    --with-python=${PYTHONBIN}

PY_PATCHPLIST=      yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
