# $NetBSD: Makefile,v 1.3 2004/06/22 12:10:23 pulahti Exp $
#

DISTNAME=	boot.${BOX}-unix
PKGNAME=	smlnj-${SML_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${SML_VERSION}/
DISTFILES=	MLRISC.tgz			\
		boot.${BOX}-unix.tgz		\
		ckit.tgz			\
		cm.tgz				\
		cml.tgz				\
		compiler.tgz			\
		config.tgz			\
		eXene.tgz			\
		ml-burg.tgz			\
		ml-lex.tgz			\
		ml-nlffi-lib.tgz		\
		ml-nlffigen.tgz			\
		ml-yacc.tgz			\
		runtime.tgz			\
		smlnj-lib.tgz			\
		system.tgz

MAINTAINER=	vnorrman@cc.hut.fi
HOMEPAGE=	http://www.smlnj.org/index.html
COMMENT=	Working version of SML/NJ Standard ML compiler

SML_VERSION=	110.46

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	smlnj-${SML_VERSION}
USE_GNU_TOOLS+=	make

SML_BASE=	${PREFIX}/lib/smlnj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin
SML_SCRIPTS=	_link-sml _run-sml _ml-build _ml-makedepend

.include "../../lang/smlnj/Makefile.common"

# create parent directory for the runtime system
pre-extract:
	${MKDIR} ${WRKDIR}/src || ${TRUE}

# make it easier to patch the runtime system
do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/config.tgz"; export extract_file;	\
		cd ${WRKDIR}; ${EXTRACT_CMD}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/runtime.tgz"; export extract_file;	\
		cd ${WRKDIR}/src; ${EXTRACT_CMD}

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# resolve definition of SML_BASE, CFLAGS in patched files
do-configure:
	if [ ${MACHINE_ARCH} = "powerpc" ]; then		\
		${AWK} '(! /^request ml-nlffi-lib$$/ &&		\
			 ! /^request ml-nlffigen$$/) { print }' \
		< ${WRKDIR}/config/targets			\
		> ${WRKDIR}/temp;				\
		${MV} ${WRKDIR}/temp ${WRKDIR}/config/targets;	\
	fi
	cd ${WRKDIR}/config;				\
	for f in ${SML_SCRIPTS}; do			\
		${CP} "$${f}" "$${f}.tmp";		\
		${SED} -e 's|@SML_BASE@|${SML_BASE}|g'	\
			< "$${f}.tmp" > "$${f}";	\
	done;						\
	cd ${WRKDIR}/src/runtime/objs;			\
	for f in *; do					\
		${CP} "$${f}" "$${f}.tmp";		\
		${SED} -e 's|@CFLAGS@|${CFLAGS}|g'	\
			< "$${f}.tmp" > "$${f}";	\
	done

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
		SMLNJ_HOME="${WRKDIR}" ./config/install.sh

# This is a work around of a bug in 110.45
post-build:
	cd ${WRKDIR}/bin;		\
	${LN} -sf .run-sml ml-burg;	\
	${LN} -sf .run-sml ml-lex;	\
	${LN} -sf .run-sml ml-nlffigen;	\
	${LN} -sf .run-sml ml-yacc;	\
	${LN} -sf .run-sml nowhere

# install target
# (see ftp://ftp.research.bell-labs.com/dist/smlnj/working/110.38/INSTALL)
# 1. create installation directories
# 2. copy the ./bin and ./lib directories across
# 3. install links to executables in $PREFIX/bin
do-install:
	${INSTALL_DATA_DIR} ${SML_BASE}
	cd ${WRKDIR} && ${PAX} -rw -pam bin lib ${SML_BASE}
	cd ${PREFIX}/bin && ${LN} -sf ../lib/smlnj/bin/* .

.include "../../mk/bsd.pkg.mk"
