# $NetBSD: Makefile,v 1.9 2016/02/24 22:32:59 tty Exp $

DISTNAME=	ansible-2.1.1.0
#PKGNAME=	${PYPKGPREFIX}-${DISTNAME} # XXX: for when package is py3x-ready
CATEGORIES=	python sysutils
MASTER_SITES=	http://releases.ansible.com/ansible/

MAINTAINER=	matthieu@beastmail.org
HOMEPAGE=	http://ansibleworks.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto

USE_TOOLS+=	gmake
PYTHON_VERSIONS_ACCEPTED=		27
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-paramiko

EGDIR=		${PREFIX}/share/examples/ansible

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_FILES.prefix+=	docs/man/man1/ansible.1
SUBST_FILES.prefix+=	docs/man/man1/ansible.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-galaxy.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-galaxy.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-playbook.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-playbook.1.asciidoc.in
SUBST_FILES.prefix+=	examples/ansible.cfg examples/hosts
SUBST_FILES.prefix+=	lib/ansible/constants.py lib/ansible/cli/galaxy.py
SUBST_FILES.prefix+=	lib/ansible/modules/core/system/ping.py
SUBST_FILES.prefix+=	lib/ansible/modules/core/system/setup.py
SUBST_FILES.prefix+=	lib/ansible/modules/extras/monitoring/nagios.py
SUBST_FILES.prefix+=	lib/ansible/utils/module_docs_fragments/openstack.py
SUBST_FILES.prefix+=	contrib/README.md contrib/inventory/cobbler.py
SUBST_FILES.prefix+=	contrib/inventory/collins.py contrib/inventory/nova.py
SUBST_FILES.prefix+=	contrib/inventory/openstack.py
SUBST_FILES.prefix+=	contrib/inventory/spacewalk.py
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=		-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.prefix+=		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"
SUBST_SED.prefix+=		-e "s,@PYSITELIB@,${PYSITELIB},"

PY_DIRS=	lib/ansible contrib/inventory

.for f in `find ${PY_DIRS} -name \*.py`
REPLACE_PYTHON+=	${f}
.endfor

MANPAGES=	ansible-doc.1 ansible-pull.1 ansible-galaxy.1 ansible-vault.1
MANPAGES+=	ansible-playbook.1 ansible.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR}/ansible
INSTALLATION_DIRS+=	${EGDIR}/playbooks

CHECK_INTERPRETER_SKIP=	share/ansible/*

MAKE_DIRS+=	${PKG_SYSCONFDIR}/ansible ${PKG_SYSCONFDIR}/ansible/facts.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/ansible/roles ${PREFIX}/share/ansible
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/action
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/callback
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/connection
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/lookup
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/vars
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/filter
MAKE_DIRS+=	${PREFIX}/share/ansible/plugins/test

pre-install:
	${FIND} ${WRKSRC} -type f -name \*.orig -delete

post-install:
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${f} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}/${EGDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
