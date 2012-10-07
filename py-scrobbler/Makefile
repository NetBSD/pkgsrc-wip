# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scrobbler-1.0.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrobbler/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://exhuma.wicked.lu/projects/python/scrobbler/
COMMENT=	Python implementation of the Audioscrobbler API

PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
