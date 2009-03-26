# $NetBSD: Makefile,v 1.4 2009/03/26 22:28:25 jihbed Exp $
#

DISTNAME=	pydb-1.25
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bashdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	splitscreen@users.sourceforge.net
HOMEPAGE=	http://sourceforge.net/projects/bashdb/
COMMENT=	The Extended Python Debugger

PKG_DESTDIR_SUPPORT= 	user-destdir

USE_TOOLS+=		gmake

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
