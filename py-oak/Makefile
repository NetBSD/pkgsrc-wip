# $NetBSD: Makefile,v 1.1.1.1 2003/11/19 13:15:02 mpasternak Exp $
#

DISTNAME=		oak-1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.digitallumber.com/TAR/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.digitallumber.com/TAR/
COMMENT=		Authoritative/recursive DNS server

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

#
# TODO: I am not sure about non-pth versions
#
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 23 22

post-patch:
	${CP} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.pkgsrc
	${SED} -e 's|@@LOCALBASE@@|${PREFIX}|g' ${WRKSRC}/setup.cfg.pkgsrc > \
		${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
