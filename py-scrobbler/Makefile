# $NetBSD: Makefile,v 1.4 2009/03/21 15:59:03 jihbed Exp $
#

DISTNAME=	scrobbler-1.0.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrobbler/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://exhuma.wicked.lu/projects/python/scrobbler/
COMMENT=	Python implementation of the Audioscrobbler API

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
