# $NetBSD: Makefile,v 1.16 2012/10/06 17:13:30 asau Exp $
#

DISTNAME=	albatross-1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.object-craft.com.au/projects/albatross/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/albatross/
COMMENT=	Toolkit for Stateful Web Applications

PKG_DESTDIR_SUPPORT= 	none

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_TOOLS+=	pax
AUTO_MKDIRS=	yes

RUNTIME_DIR?=	/var/run/albatross
LOGDIR?=	/var/log/albatross
EXAMPLEDIR=	${DESTDIR}${PREFIX}/share/examples/albatross
LOGFILE?=	${LOGDIR}/al-session-daemon.log
PIDFILE?=	${RUNTIME_DIR}/session-daemon.pid

ALBATROSS_USER=	albatross
ALBATROSS_GROUP=albatross

FILES_SUBST+=	ALBATROSS_USER=${ALBATROSS_USER:Q}
FILES_SUBST+=	ALBATROSS_GROUP=${ALBATROSS_GROUP:Q}
FILES_SUBST+=	RUNTIME_DIR=${RUNTIME_DIR:Q}
FILES_SUBST+=	LOGDIR=${LOGDIR:Q}
FILES_SUBST+=	LOGFILE=${LOGFILE:Q}
FILES_SUBST+=	PIDFILE=${PIDFILE:Q}

RCD_SCRIPTS=	al_session_daemon
PKG_GROUPS=	${ALBATROSS_USER}
PKG_USERS=	${ALBATROSS_USER}:${ALBATROSS_GROUP}

OWN_DIRS_PERMS=	${RUNTIME_DIR} ${ALBATROSS_USER} ${ALBATROSS_GROUP} 0750
OWN_DIRS_PERMS+=${LOGDIR} ${ALBATROSS_USER} ${ALBATROSS_GROUP} 0750

PYTHON_PATCH_SCRIPTS=	samples/extension/cal.py
PYTHON_PATCH_SCRIPTS+=	samples/form4/form.py
PYTHON_PATCH_SCRIPTS+=	samples/paginate/paginate.py
PYTHON_PATCH_SCRIPTS+=	samples/popview1/popview.py
PYTHON_PATCH_SCRIPTS+=	samples/popview2/popview.py
PYTHON_PATCH_SCRIPTS+=	samples/popview3/popview.py
PYTHON_PATCH_SCRIPTS+=	samples/popview4/popview.py
PYTHON_PATCH_SCRIPTS+=	samples/random/random.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/content1/content.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/content2/content.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/form1/form.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/form2/form.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/form3/form.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/simple1/simple.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/simple2/simple.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/simple3/simple.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/simple4/simple.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/simple5/simple.py
PYTHON_PATCH_SCRIPTS+=	samples/templates/stream/stream.py
PYTHON_PATCH_SCRIPTS+=	samples/tree1/tree.py
PYTHON_PATCH_SCRIPTS+=	samples/tree2/tree.py
PYTHON_PATCH_SCRIPTS+=	samples/tree3/tree.py

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type f \! -name \.cvsignore \
		-print | pax -rw -pp -pm ${EXAMPLEDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
