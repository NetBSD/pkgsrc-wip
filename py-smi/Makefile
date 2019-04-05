# $NetBSD$

DISTNAME=	pysmi-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/etingof/pysmi
COMMENT=	SNMP SMI/MIB Parser
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply

USE_LANGUAGES=	# none

post-install:
	for f in mibcopy mibdump; do \
	${MV} ${DESTDIR}${PREFIX}/bin/$$f.py \
	    ${DESTDIR}${PREFIX}/bin/$$f-${PYVERSSUFFIX}.py || ${TRUE}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
