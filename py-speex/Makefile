# $NetBSD: Makefile,v 1.4 2004/03/30 22:31:28 mpasternak Exp $
#

DISTNAME=		pySpeex-0.2
PKGNAME=		${PYPKGPREFIX}-speex-0.2
WRKSRC=			${WRKDIR}/${DISTNAME:S/-0.2//}
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pySpeex/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pySpeex/
COMMENT=		Speex bindings for Python; see speex package for details

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0:../../lang/py-pyrex

.include "../../lang/python/extension.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
