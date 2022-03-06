# $NetBSD$

DISTNAME=	objection-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=o/objection/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sensepost/objection
COMMENT=	Runtime mobile exploration
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-delegator-[0-9]*:../../wip/py-delegator
DEPENDS+=	${PYPKGPREFIX}-frida-tools-[0-9]*:../../wip/py-frida-tools
DEPENDS+=	${PYPKGPREFIX}-litecli-[0-9]*:../../wip/py-litecli
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tabulate-[0-9]*:../../textproc/py-tabulate

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
