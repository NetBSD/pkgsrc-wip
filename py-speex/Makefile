# $NetBSD: Makefile,v 1.2 2003/11/26 17:19:09 mpasternak Exp $
#

DISTNAME=		pySpeex-0
PKGNAME=		${PYPKGPREFIX}-speex
WRKSRC=			${WRKDIR}/python/
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pySpeex/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pySpeex/
COMMENT=		Speex bindings for Python; see speex package for details

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
