# $NetBSD: Makefile,v 1.2 2004/07/18 15:13:43 ppostma Exp $
#

DISTNAME=		DirectoryStorage_1_1_7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_1_1_7/-1.1.7/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirstorage/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://dirstorage.sourceforge.net/
COMMENT=		Storage for ZODB, that uses files and directories

USE_BUILDLINK3=		yes
NO_CONFIGURE=		# defined
PYTHON_PATCH_SCRIPTS=	${TOOLS}
PY_PATCHPLIST=		yes

# package settings

TARGET_DIR=		${PREFIX}/${PYSITELIB}/DirectoryStorage
DOCS_DIR=		${PREFIX}/share/doc/DirectoryStorage

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
	cd ${WRKSRC} && \
	for a in ${MODULES}; do \
		${INSTALL_DATA} $$a ${TARGET_DIR}/$$a; \
	done
	${INSTALL_DATA_DIR} ${TARGET_DIR}/DirectoryStorageToolkit
	${INSTALL_DATA_DIR} ${TARGET_DIR}/DirectoryStorageToolkit/management
	cd ${WRKSRC}/DirectoryStorageToolkit && \
	for a in DirectoryStorageToolkit.py __init__.py; do \
		${INSTALL_DATA} $$a ${TARGET_DIR}/DirectoryStorageToolkit/$$a; \
	done
	cd ${WRKSRC}/DirectoryStorageToolkit/management && \
	for a in *; do \
		${INSTALL_DATA} $$a ${TARGET_DIR}/DirectoryStorageToolkit/management/$$a; \
	done
	#
	# install scripts in bin/
	#
	cd ${WRKSRC} && \
	for a in ${TOOLS}; do \
		${INSTALL_SCRIPT} $$a ${PREFIX}/bin/$$a${PYPKGSUFFIX}; \
	done
	#
	# install documentation
	#
	${INSTALL_DATA_DIR} ${DOCS_DIR}
	cd ${WRKSRC}/doc && \
	for a in *; do \
		${INSTALL_DATA} $$a ${DOCS_DIR}/$$a; \
	done

.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
