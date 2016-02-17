# $NetBSD$

DISTNAME=	ansible-junos-stdlib-1.2.0
CATEGORIES=	sysutils net
MASTER_SITES=	-https://github.com/Juniper/${PKGBASE}/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/${PKGBASE}
COMMENT=	Ansible library for JunOS routers
LICENSE=	apache-2.0

USE_TOOLS=	pax
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	27 26

REPLACE_PYTHON+=	docs/ansible2rst.py
REPLACE_PYTHON+=	library/junos_get_config
REPLACE_PYTHON+=	library/junos_rollback
REPLACE_PYTHON+=	tools/sw_upgrade

DEPENDS+=	ansible>=1.5:../../sysutils/ansible
DEPENDS+=	${PYPKGPREFIX}-junos-eznc>=1.2.2:../../net/py-junos-eznc
# Not packaged yet
#DEPENDS+=	${PYPKGPREFIX}-netconify>=1.0.1:../../wip/py-netconify

# Pkgsrc frowns on this, pkglint says "use CONF_FILES framework"
# However, this is what "ansible-galaxy install Juniper.junos" does,
# and we simply replicate that here.
INSTALLATION_DIRS=	${PKG_SYSCONFDIR}/ansible/roles/Juniper.junos

do-build:

do-install:
	(cd ${WRKSRC}; pax -rw . ${DESTDIR}/${PKG_SYSCONFDIR}/ansible/roles/Juniper.junos)

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
