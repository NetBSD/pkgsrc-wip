# $NetBSD: Makefile,v 1.1.1.1 2003/06/22 13:48:41 marc Exp $
#

DISTNAME=		ht2html-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ht2html/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://ht2html.sourceforge.net/
COMMENT=		simple web page templating system

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes

PYTHON_PATCH_SCRIPTS=	ht2html.py

DOCDIR=			${PREFIX}/share/doc/html/ht2html
PAX_SUBST=		-s '/calcroot\.py[co]*//' -s '/ht2html\.py[co]*//'
PY_PAX=			${PAX} ${PAX_SUBST} -rw -pp -pm

do-build:
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py \
		${WRKSRC}
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${DOCDIR}
	cd ${WRKSRC} && ${PY_PAX} *.py* ${PREFIX}/${PYSITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/ht2html.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
