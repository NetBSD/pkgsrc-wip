# $NetBSD: Makefile,v 1.2 2009/05/19 23:22:43 jihbed Exp $
#

DISTNAME=	rthread-0.1.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.cs.tut.fi/~ask/rthread/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.cs.tut.fi/~ask/rthread/
COMMENT=	Distributed computing with remote threads in Python
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes


.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
