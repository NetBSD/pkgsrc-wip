# $NetBSD$

DISTNAME=	ansible-junos-stdlib-1.2.0
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Juniper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/${PKGBASE}
COMMENT=	Ansible library for JunOS routers
LICENSE=	apache-2.0

USE_TOOLS=	pax bash
USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27

REPLACE_PYTHON+=	docs/ansible2rst.py
REPLACE_PYTHON+=	library/junos_get_config
REPLACE_PYTHON+=	library/junos_rollback
REPLACE_PYTHON+=	tools/sw_upgrade

REPLACE_BASH+=		env-setup

DEPENDS+=	ansible>=1.5:../../sysutils/ansible
DEPENDS+=	${PYPKGPREFIX}-junos-eznc>=1.2.2:../../net/py-junos-eznc
DEPENDS+=	${PYPKGPREFIX}-junos-netconify>=1.0.1:../../wip/py-junos-netconify

INSTALLATION_DIRS=	${PREFIX}/share/ansible/roles/Juniper.junos

do-build:

do-install:
	(cd ${WRKSRC}; pax -rw -pp . ${DESTDIR}/${PREFIX}/share/ansible/roles/Juniper.junos)

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
