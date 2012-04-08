# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:47 thomasklausner Exp $
#

DISTNAME=	py-libmpdclient2-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	audio devel
MASTER_SITES=	http://incise.org/files/dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.incise.org/index.cgi/py-libmpdclient2
COMMENT=	Python bindings to the mpd access library

WRKSRC=		${WRKDIR}/py-libmpdclient2

PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes

.include "../../audio/libmpd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
