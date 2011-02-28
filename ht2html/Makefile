# $NetBSD: Makefile,v 1.8 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=		ht2html-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ht2html/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ht2html.sourceforge.net/
COMMENT=		Simple web page templating system

USE_TOOLS+=		pax
PY_PATCHPLIST=		yes

PYTHON_PATCH_SCRIPTS=	ht2html.py

EGDIR=			${PREFIX}/share/examples/ht2html
EGFILES=		BAWGenerator.py JPyLocalGenerator.py
EGFILES+=		IPC8Generator.py PDOGenerator.py
EGFILES+=		JPyGenerator.py SelfGenerator.py

LIBFILES=		Banner.* HTParser.* LinkFixer.*
LIBFILES+=		Sidebar.* Skeleton.* StandardGenerator.*

do-build:
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py \
		${PY_COMPILE_EXCLUDE} ${WRKSRC}
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${PY_COMPILE_EXCLUDE} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc && pax -rw -pp -pm . ${EGDIR}
	for egfile in ${EGFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${egfile} ${EGDIR}; \
	done
	for libfile in ${LIBFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${libfile} \
			${PREFIX}/${PYSITELIB}; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/ht2html.py ${PREFIX}/bin

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
