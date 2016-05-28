# $NetBSD: Makefile,v 1.9 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=		willow-1.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		http://www.digitallumber.com/TAR/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digitallumber.com/
COMMENT=		Content-filtering proxy server


PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

post-patch:
	${CP} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.pkgsrc
	${SED} -e 's|@@LOCALBASE@@|${PREFIX}|g' ${WRKSRC}/setup.cfg.pkgsrc > \
		${WRKSRC}/setup.cfg

DEPENDS+=	${PYPKGPREFIX}-oak>=1.2:../../wip/py-oak

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
