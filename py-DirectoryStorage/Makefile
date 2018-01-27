# $NetBSD: Makefile,v 1.12 2014/01/25 10:45:27 thomasklausner Exp $
#

DISTNAME=		DirectoryStorage_1_1_7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_1_1_7/-1.1.7/}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirstorage/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dirstorage.sourceforge.net/
COMMENT=		Storage for ZODB, that uses files and directories

NO_CONFIGURE=	yes
REPLACE_PYTHON=	${TOOLS}
PY_PATCHPLIST=	yes

AUTO_MKDIRS=		yes

# package settings

TARGET_DIR=		${DESTDIR}${PREFIX}/${PYSITELIB}/DirectoryStorage
DOCS_DIR=		${DESTDIR}${PREFIX}/share/doc/DirectoryStorage

TOOLS=			replica.py mkds.py snapshot.py checkds.py \
			backup.py dumpdsf.py whatsnew.py

MODULES=		BaseDirectoryStorage.py BaseFilesystem.py Filesystem.py \
			Full.py LocalFilesystem.py Minimal.py PosixFilesystem.py \
			Setup __init__.py component.xml config.py formats.py \
			pipeline.py readdir.so utils.py

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} compile.py

do-install:
	#
	# install Python modules
	#
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	set -e; cd ${WRKSRC}; \
	for a in ${MODULES}; do \
		${INSTALL_DATA} "$$a" ${TARGET_DIR}/"$$a"; \
	done
	${INSTALL_DATA_DIR} ${TARGET_DIR}/DirectoryStorageToolkit
	${INSTALL_DATA_DIR} ${TARGET_DIR}/DirectoryStorageToolkit/management
	set -e; cd ${WRKSRC}/DirectoryStorageToolkit; \
	for a in DirectoryStorageToolkit.py __init__.py; do \
		${INSTALL_DATA} "$$a" ${TARGET_DIR}/DirectoryStorageToolkit/; \
	done
	set -e; cd ${WRKSRC}/DirectoryStorageToolkit/management; \
	for a in *; do \
		${INSTALL_DATA} "$$a" ${TARGET_DIR}/DirectoryStorageToolkit/management/; \
	done
	#
	# install scripts in bin/
	#
	set -e; cd ${WRKSRC}; \
	for a in ${TOOLS}; do \
		${INSTALL_SCRIPT} "$$a" ${DESTDIR}${PREFIX}/bin/"$$a"${PYPKGSUFFIX}; \
	done
	#
	# install documentation
	#
	${INSTALL_DATA_DIR} ${DOCS_DIR}
	set -e; cd ${WRKSRC}/doc; \
	for a in *; do \
		${INSTALL_DATA} "$$a" ${DOCS_DIR}/; \
	done

#.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
