# $NetBSD: Makefile,v 1.3 2006/10/12 21:13:42 shattered Exp $
#

DISTNAME=		pydb-1.17
CATEGORIES=		python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bashdb/}

MAINTAINER=		splitscreen@users.sourceforge.net
HOMEPAGE=		http://sourceforge.net/projects/bashdb/
COMMENT=		The Extended Python Debugger

USE_TOOLS+=		gmake

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=    --with-python=${PYTHONBIN}

PY_PATCHPLIST=      yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
