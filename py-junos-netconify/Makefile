# $NetBSD$

DISTNAME=	py-junos-netconify-1.0.2
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	net
GITHUB_PROJECT=	py-junos-netconify
MASTER_SITES=	${MASTER_SITE_GITHUB:=Juniper/}
EGG_NAME=	${DISTNAME:S/^py-//:S/-/_/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/${PKGBASE}
COMMENT=	Junos console/bootstrap automation Python module
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-serial:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-paramiko:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-lxml:../../textproc/py-lxml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
