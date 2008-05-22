# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:47 tnn2 Exp $
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
