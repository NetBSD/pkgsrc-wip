# $NetBSD: Makefile,v 1.1.1.1 2003/11/24 01:41:14 mpasternak Exp $
#

DISTNAME=		pySpeex
PKGNAME=		${PYPKGPREFIX}-speex
WRKSRC=			${WRKDIR}/python/
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pySpeex/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pySpeex/
COMMENT=		speex bindings for Python; see speex package for details

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
