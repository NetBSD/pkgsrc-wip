# $NetBSD: Makefile,v 1.1 2025/03/05 02:13:13 scole Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcl.tk/
COMMENT=	Tool Command Language, a dynamic language
LICENSE=	2-clause-bsd

# xxx
#.include "../../lang/tcl/Makefile.version"
.include "Makefile.version"

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/tcl${TCL_VERSION}

USE_GCC_RUNTIME=	yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # because of the nested itcl
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_TARGET=		install
USE_TOOLS+=		ln mkdir mv

CONFIGURE_ARGS+=	--without-tzdata

CONFIGURE_ARGS+=	--enable-zipfs
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip

PKGCONFIG_OVERRIDE+=	unix/tcl.pc.in

CHECK_PORTABILITY_SKIP=	win/configure

# The test target gives better results when not run as root.
TEST_TARGET=		test

# xxx
#.include "../../lang/tcl/options.mk"
.include "options.mk"

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

# Fix the exec path in bin/sqlite3_analyzer:
#
#	#! /bin/sh
#	# single-line sh comment, multi-line tcl comment \
#	exec tclsh "$0" ${1+"$@"}
#
SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	post-build
SUBST_FILES.tclsh+=	pkgs/sqlite*/compat/sqlite3/spaceanal.tcl
SUBST_SED.tclsh+=	-e '\|^\#! */bin/sh|,+2s|^exec tclsh |exec ${PREFIX}/bin/tclsh |'

PLIST_SUBST+=		SONUM=${TCL_SONUM}
PLIST_SUBST+=		BASEVER=${TCL_BASEVER}
PLIST_SUBST+=		ITCL_VERSION=${ITCL_VERSION}
PLIST_SUBST+=		SQLITE3_VERSION=${SQLITE3_VERSION}
PLIST_SUBST+=		TDBC_VERSION=${TDBC_VERSION}
PLIST_SUBST+=		THREAD_VERSION=${THREAD_VERSION}

SUBST_CLASSES+=		sqllink
SUBST_STAGE.sqllink=	pre-configure
SUBST_FILES.sqllink=	pkgs/sqlite${SQLITE3_VERSION}/configure
SUBST_SED.sqllink=	-e "/LIBS=/s|-lsqlite3|-L${BUILDLINK_PREFIX.sqlite3}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3|g"

# install-sh requires $SHELL is an extremely close match to /bin/sh
MAKE_ENV+=		SHELL=${SH:Q}

# xxx software that comes with the tcl distribution, could put be put
# in their own individual pkgsrc packages if they aren't already there
EMB_SRC=	itcl-4.3.2 sqlite-3.47.2 tdbc-1.1.10 tdbcmysql-1.1.10 \
		tdbcodbc-1.1.10 tdbcpostgres-1.1.10 tdbcsqlite-3-1.1.10 \
		thread-3.0.1
# xxx maybe add some kind of rule in mk/pkgformat/pkg/check.mk for
# something like
# 	${CHECK_BUNDLED_PKG_VULNERABILItIES} ${EMB_SRC}
# or
#	${AUDIT_PACKAGE} itcl-4.3.2
#
# other packages have this issue as well (e.g. ../graphics/tkImg)
VFILE=		${_EXTRACT_PKGVULNDIR:sh}/pkg-vulnerabilities
pre-fetch:
.if exists(${VFILE})
.  if !empty(ALLOW_VULNERABLE_PACKAGES:tl:Mno)
	for i in ${EMB_SRC}; do \
		${PKG_ADMIN} audit-pkg $$i || \
		 { ${FAIL_MSG} "embedded source $$i has vulnerabilities. "\
			"Define ALLOW_VULNERABLE_PACKAGES if necessary"; \
		 exit 1; } \
	done
.  endif
.endif

.if ${OPSYS} == "Darwin"
post-build:
.  for lib in itcl${ITCL_VERSION}/libitcl${ITCL_VERSION}.dylib \
	      sqlite${SQLITE3_VERSION}/libsqlite${SQLITE3_VERSION}.dylib \
	      tdbc${TDBC_VERSION}/libtdbc${TDBC_VERSION}.dylib \
	      tdbcmysql${TDBC_VERSION}/libtdbcmysql${TDBC_VERSION}.dylib \
	      tdbcodbc${TDBC_VERSION}/libtdbcodbc${TDBC_VERSION}.dylib \
	      tdbcpostgres${TDBC_VERSION}/libtdbcpostgres${TDBC_VERSION}.dylib \
	      tdbcsqlite${TDBC_VERSION}/libtdbcsqlite${TDBC_VERSION}.dylib \
	      thread${THREAD_VERSION}/libthread${THREAD_VERSION}.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${WRKSRC}/unix/pkgs/${lib}
.  endfor
.endif

post-install:
	cd ${WRKSRC}/unix && ${MAKE} \
		BIN_INSTALL_DIR=${DESTDIR}${PREFIX}/bin \
		LIB_INSTALL_DIR=${DESTDIR}${PREFIX}/lib \
		CONFIG_INSTALL_DIR=${DESTDIR}${PREFIX}/lib \
		SCRIPT_INSTALL_DIR=${DESTDIR}${PREFIX}/lib/tcl${TCL_BASEVER} \
		INCLUDE_INSTALL_DIR=${DESTDIR}${PREFIX}/include \
		PRIVATE_INCLUDE_INSTALL_DIR=${DESTDIR}${PREFIX}/include \
		MAN_INSTALL_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
		install-binaries install-libraries install-headers \
		install-private-headers install-msgs
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs tclsh${TCL_BASEVER} tclsh
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3 && ${MV} Thread.3 Tcl_Thread.3

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=${SQLITE3_VERSION}
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
