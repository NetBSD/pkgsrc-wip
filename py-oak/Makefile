# $NetBSD: Makefile,v 1.5 2005/10/25 00:30:43 rillig Exp $
#

DISTNAME=		oak-1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://www.digitallumber.com/software/oak/code/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.digitallumber.com/TAR/
COMMENT=		Authoritative/recursive DNS server

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

#
# TODO: I am not sure about non- versions
#
PYTHON_VERSIONS_ACCEPTED=	23 22

post-patch:
	${CP} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.pkgsrc
	${SED} -e 's|@@LOCALBASE@@|${PREFIX}|g' ${WRKSRC}/setup.cfg.pkgsrc > \
		${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
