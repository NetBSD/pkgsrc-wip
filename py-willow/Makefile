# $NetBSD: Makefile,v 1.3 2004/04/19 19:25:16 mpasternak Exp $
#

DISTNAME=		willow-1.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		http://www.digitallumber.com/TAR/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.digitallumber.com/
COMMENT=		Content-filtering proxy server

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

#
# TODO: I am not sure about non-pth versions
#
PYTHON_VERSIONS_ACCEPTED=	23pth 23 22pth 22

post-patch:
	${CP} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.pkgsrc
	${SED} -e 's|@@LOCALBASE@@|${PREFIX}|g' ${WRKSRC}/setup.cfg.pkgsrc > \
		${WRKSRC}/setup.cfg

DEPENDS+=	${PYPKGPREFIX}-oak>=1.2:../../wip/py-oak

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
