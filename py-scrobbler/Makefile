# $NetBSD: Makefile,v 1.1.1.1 2007/12/11 10:45:11 netcap Exp $
#

DISTNAME=	scrobbler-1.0.0a1
PKGNAME=	py-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrobbler/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://exhuma.wicked.lu/projects/python/scrobbler/
COMMENT=	Python implementation of the Audioscrobbler API

PYTHON_VERSIONS_ACCEPTED=	24 23 22
PY_PATCHPLIST=			yes
PYDISTUTILSPKG=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
