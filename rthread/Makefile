# $NetBSD: Makefile,v 1.1.1.1 2009/03/23 21:45:44 jihbed Exp $
#

DISTNAME=	rthread-0.1.1
CATEGORIES=	devel parallel
MASTER_SITES=	http://www.cs.tut.fi/~ask/rthread/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.cs.tut.fi/~ask/rthread/
COMMENT=	Distributed computing with remote threads in Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes


.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
