# $NetBSD: Makefile,v 1.9 2016/02/24 22:32:59 tty Exp $

DISTNAME=	ansible-2.4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
DEPENDS+=	${PYPKGPREFIX}-jxmlease-[0-9]*:../../textproc/py-jxmlease

.include "../../lang/python/pyversion.mk"

.if !empty(PYPKGPREFIX:Mpy2*)
DEPENDS+=	${PYPKGPREFIX}-subprocess32-[0-9]*:../../devel/py-subprocess32
.endif

USE_TOOLS+=	gmake
PYTHON_VERSIONS_ACCEPTED= 36 35 34 27

EGDIR=		${PREFIX}/share/examples/ansible

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	contrib/README.md
SUBST_FILES.prefix+=	contrib/inventory/cobbler.py
SUBST_FILES.prefix+=	contrib/inventory/collins.py
SUBST_FILES.prefix+=	contrib/inventory/nova.py
SUBST_FILES.prefix+=	contrib/inventory/openstack.py
SUBST_FILES.prefix+=	contrib/inventory/spacewalk.py
SUBST_FILES.prefix+=	docs/man/man1/ansible.1
SUBST_FILES.prefix+=	docs/man/man1/ansible.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-doc.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-doc.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-galaxy.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-galaxy.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-playbook.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-playbook.1.asciidoc.in
SUBST_FILES.prefix+=	docs/man/man1/ansible-pull.1
SUBST_FILES.prefix+=	docs/man/man1/ansible-pull.1.asciidoc.in
SUBST_FILES.prefix+=	examples/ansible.cfg
SUBST_FILES.prefix+=	examples/hosts
SUBST_FILES.prefix+=	lib/ansible/constants.py
SUBST_FILES.prefix+=	lib/ansible/cli/galaxy.py
SUBST_FILES.prefix+=	lib/ansible/modules/monitoring/nagios.py
SUBST_FILES.prefix+=	lib/ansible/modules/system/ping.py
SUBST_FILES.prefix+=	lib/ansible/modules/system/setup.py
SUBST_FILES.prefix+=	lib/ansible/utils/module_docs_fragments/openstack.py
SUBST_MESSAGE.prefix=	Fixing PREFIX, PYSITELIB, and PKG_SYSCONFDIR path.
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.prefix+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g"
SUBST_SED.prefix+=	-e "s,@PYSITELIB@,${PYSITELIB},"

SUBST_CLASSES+=		subprocess
SUBST_STAGE.subprocess=	pre-configure
SUBST_FILES.subprocess+= contrib/inventory/fleet.py
SUBST_FILES.subprocess+= contrib/inventory/spacewalk.py
SUBST_FILES.subprocess+= contrib/inventory/vagrant.py
SUBST_FILES.subprocess+= lib/ansible/cli/__init__.py
SUBST_FILES.subprocess+= lib/ansible/cli/config.py
SUBST_FILES.subprocess+= lib/ansible/executor/module_common.py
SUBST_FILES.subprocess+= lib/ansible/module_utils/basic.py
SUBST_FILES.subprocess+= lib/ansible/module_utils/service.py
SUBST_FILES.subprocess+= lib/ansible/modules/cloud/lxc/lxc_container.py
SUBST_FILES.subprocess+= lib/ansible/modules/crypto/openssl_certificate.py
SUBST_FILES.subprocess+= lib/ansible/modules/database/mysql/mysql_db.py
SUBST_FILES.subprocess+= lib/ansible/modules/system/alternatives.py
SUBST_FILES.subprocess+= lib/ansible/modules/system/service.py
SUBST_FILES.subprocess+= lib/ansible/modules/utilities/logic/async_wrapper.py
SUBST_FILES.subprocess+= lib/ansible/parsing/vault/__init__.py
SUBST_FILES.subprocess+= lib/ansible/playbook/role/requirement.py
SUBST_FILES.subprocess+= lib/ansible/plugins/callback/osx_say.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/buildah.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/chroot.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/docker.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/iocage.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/jail.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/libvirt_lxc.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/local.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/persistent.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/saltstack.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/ssh.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/winrm.py
SUBST_FILES.subprocess+= lib/ansible/plugins/connection/zone.py
SUBST_FILES.subprocess+= lib/ansible/plugins/inventory/script.py
SUBST_FILES.subprocess+= lib/ansible/plugins/lookup/cyberarkpassword.py
SUBST_FILES.subprocess+= lib/ansible/plugins/lookup/lines.py
SUBST_FILES.subprocess+= lib/ansible/plugins/lookup/passwordstore.py
SUBST_FILES.subprocess+= lib/ansible/plugins/lookup/pipe.py
SUBST_FILES.subprocess+= lib/ansible/utils/cmd_functions.py
SUBST_FILES.subprocess+= lib/ansible/utils/display.py
SUBST_FILES.subprocess+= lib/ansible/utils/ssh_functions.py
SUBST_FILES.subprocess+= test/runner/import/lib/ansible/module_utils/basic.py
SUBST_FILES.subprocess+= test/runner/import/lib/ansible/module_utils/service.py
SUBST_FILES.subprocess+= test/runner/lib/util.py
SUBST_FILES.subprocess+= test/runner/units/test_diff.py
SUBST_FILES.subprocess+= test/sanity/code-smell/ansible-var-precedence-check.py
SUBST_FILES.subprocess+= test/sanity/validate-modules/main.py
SUBST_FILES.subprocess+= test/utils/docker/vcenter-simulator/flask_control.py
SUBST_MESSAGE.subprocess=	Fix subprocess to subprocess32 import
SUBST_SED.subprocess=	-e "/^import subprocess/{i\\$(.newline)import os, sys$(.newline)i\\$(.newline)if os.name == 'posix' and sys.version_info[0] < 3:$(.newline)i\\$(.newline)\\    import subprocess32 as subprocess$(.newline)i\\$(.newline)else:$(.newline)i\\$(.newline)\\    import subprocess$(.newline)d$(.newline)}"

PY_DIRS=	lib/ansible
PY_DIRS+=	contrib/inventory

REPLACE_PYTHON= `find ${PY_DIRS} -name \*.py`

MANPAGES=	ansible-doc.1 ansible-pull.1 ansible-galaxy.1 ansible-vault.1
MANPAGES+=	ansible-playbook.1 ansible.1

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/ansible
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
