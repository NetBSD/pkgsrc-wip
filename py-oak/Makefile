# $NetBSD: Makefile,v 1.10 2012/10/07 12:25:33 asau Exp $
#

DISTNAME=		oak-1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.digitallumber.com/software/oak/code/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digitallumber.com/software/oak/
COMMENT=		Authoritative/recursive DNS server


PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

post-patch:
	${CP} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.pkgsrc
	${SED} -e 's|@@LOCALBASE@@|${PREFIX}|g' ${WRKSRC}/setup.cfg.pkgsrc > \
		${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
