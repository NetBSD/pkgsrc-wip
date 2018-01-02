# $NetBSD$

DISTNAME=	DenyHosts-2.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denyhosts/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/denyhosts/denyhosts/2.6/
COMMENT=	Block hosts with too many failed login attempts
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py \
			README.txt \
			daemon-control-dist \
			denyhosts.cfg-dist
SUBST_SED.setup=	-e "s|/usr/share|${PREFIX}/share|g"

SUBST_CLASSES+=		lock
SUBST_STAGE.lock=	post-patch
SUBST_FILES.lock=	README.txt \
			daemon-control-dist \
			denyhosts.cfg-dist
SUBST_SED.lock=		-e "s|/var/lock/subsys|/var/run|g"

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	post-patch
SUBST_FILES.bin=	README.txt \
			daemon-control-dist
SUBST_SED.bin=		-e "s|/usr/bin/denyhosts.py|${PREFIX}/bin/denyhosts.py|g"

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	daemon-control-dist \
			setup.py \
			denyhosts.py \
			plugins/test_deny.py
SUBST_SED.python=	-e "s|/usr/bin/env python|${PYTHONBIN}|g"
SUBST_SED.python+=	-e "s|/usr/bin/python|${PYTHONBIN}|g"

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	denyhosts.cfg-dist
SUBST_SED.config=	-e "s|/etc/hosts.deny|${DENIED_HOSTS_FILE}|g"
SUBST_SED.config+=	-e "s|DAEMON_SLEEP = 30s|DAEMON_SLEEP = 10s|g"
SUBST_SED.config+=	-e "s|\#BLOCK_SERVICE = ALL|BLOCK_SERVICE = ALL|g"
SUBST_SED.config+=	-e "s|BLOCK_SERVICE  = sshd|\#BLOCK_SERVICE  = sshd|g"

SUBST_CLASSES+=		env
SUBST_STAGE.env=	post-patch
SUBST_FILES.env=	scripts/*.py
SUBST_SED.env=		-e 's|/bin/env python|${PYTHONBIN}|g'

DENIED_HOSTS_FILE=	${PREFIX}/etc/hosts.deniedssh

.include "../../mk/bsd.prefs.mk"

post-install:
	touch ${DENIED_HOSTS_FILE}
	chmod 600 ${DENIED_HOSTS_FILE}
.if !exists(${DESTDIR}${PREFIX}/share/denyhosts/denyhosts.cfg)
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/share/denyhosts/denyhosts.cfg-dist \
		${DESTDIR}${PREFIX}/share/denyhosts/denyhosts.cfg
.endif
.if ${OPSYS} == Linux && !exists(/etc/init.d/denyhosts)
	${ECHO} "Linux init scripts are in"
	${ECHO} ${DESTDIR}${PREFIX}/share/denyhosts/daemon-control-dist
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
