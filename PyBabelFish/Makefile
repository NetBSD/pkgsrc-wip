# $NetBSD: Makefile,v 1.17 2014/05/09 07:38:41 thomasklausner Exp $

DISTNAME=		PyBabelPhish-2.0_All_Platforms
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_All_Platforms//}
WRKSRC=			${WRKDIR}/PyBabelPhish-Install
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pythonol/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.phrozensmoke.com/projects/pythonol/
COMMENT=		Gtk-based frontend for several translation services on web


PY_PATCHPLIST=		yes
NO_CONFIGURE=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

PYFILES=	URLRead.py pybabelfish.py pyfilter.py pytheme.py \
		pythonol_festival.py symbolbar.py

TARGET_DIR=	${PREFIX}/${PYSITELIB}/BabelPhish
SCRIPTNAME=	pybabelfish

do-build:
	cd ${WRKSRC};							\
	${ECHO} '#! ${SH}' >${SCRIPTNAME};				\
	${ECHO} 'exec ${PYTHONBIN} ${PREFIX}/${PYSITELIB}/BabelPhish/pybabelfish.py' >>${SCRIPTNAME};

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/pixmaps

	for a in ${PYFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${TARGET_DIR}/$$a; \
	done
	for a in ${WRKSRC}/pixmaps/*; do \
		${INSTALL_DATA} $$a ${TARGET_DIR}/pixmaps/`${BASENAME} $$a`; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPTNAME} ${PREFIX}/bin

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
