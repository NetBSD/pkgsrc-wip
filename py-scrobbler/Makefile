# $NetBSD: Makefile,v 1.2 2007/12/11 11:03:44 netcap Exp $
#

DISTNAME=	scrobbler-1.0.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrobbler/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://exhuma.wicked.lu/projects/python/scrobbler/
COMMENT=	Python implementation of the Audioscrobbler API

PYTHON_VERSIONS_ACCEPTED=	25 24 23 22
PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
