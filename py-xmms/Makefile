# $NetBSD: Makefile,v 1.1.1.1 2004/01/23 16:56:42 minskim Exp $

DISTNAME=	pyxmms-2.02
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	audio
MASTER_SITES=	http://people.via.ecp.fr/~flo/2002/PyXMMS/dist/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.via.ecp.fr/~flo/index.en.xhtml\#PyXMMS_and_PyXMMS-remote
COMMENT=	Python interface to XMMS

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	setup.cfg
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX}/,g'

.include "../../audio/xmms/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
