# $NetBSD: Makefile,v 1.7 2004/04/26 10:50:43 johnrshannon Exp $
CVS_DATE=	Thu Nov 20 01:28:29 UTC 2003

DISTNAME=	gdbada-5.3
CATEGORIES=	devel

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://libre.act-europe.fr/GDB/
COMMENT=        GNAT GDB : An Ada 95 Debugger

GDB_SUBPREFIX=	gdbada
GDB_PREFIX=	${PREFIX}/${GDB_SUBPREFIX}
GNU_CONFIGURE=          YES
USE_BUILDLINK3=         YES
USE_PKGLOCALEDIR=       YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
REPLACE_LOCALEDIR_PATTERNS+=    Make-in
TEST_TARGET=    	check
USE_LIBTOOL=		YES
HAS_CONFIGURE=		YES
INFO_DIR=		${GDB_PREFIX}/info
LIB_DIR=		${GDB_PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${GDB_PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${GDB_PREFIX}
CONFIGURE_ARGS+=	--infodir=${INFO_DIR}
CONFIGURE_ARGS+=	--libdir=${LIB_DIR}
CONFIGURE_ARGS+=	--includedir=${GDB_PREFIX}/include
CONFIGURE_ARGS+=	--mandir=${GDB_PREFIX}/man
CONFIGURE_ARGS+=	--datadir=${GDB_PREFIX}/share
# We don't seem to be able to control where locale data goes, so:
CONFIGURE_ARGS+=	--disable-nls
USE_MAKEINFO=		YES
USE_NEW_TEXINFO=	YES
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
NO_CHECKSUM=	yes
DIST_SUBDIR=	${PKGNAME}
CVS_CMD?=	cvs -z3 -q
CVSROOT=	:pserver:anoncvs@libre.act-europe.fr:/anoncvs
STAMPFILE=	${DISTDIR}/${DIST_SUBDIR}/.timestamp
do-fetch:
	@if [ ! -e ${WRKDIR}/.extract_done ] ; then \
		if [ ! -e ${STAMPFILE} ] ; then \
			${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
			cd ${DISTDIR}/${DIST_SUBDIR} ; \
			unset CVS_RSH CVS_SERVER || ${TRUE} ; \
			${ECHO_MSG} ">> Attempting to CVS checkout from ${CVSROOT}." ;\
			if ${CVS_CMD} -d ${CVSROOT} co -P gdb-5.3 ; \
			then \
				( ${ECHO} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
				exit ; \
			fi ; \
			${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
			${ECHO_MSG} ">> Please try again later."; \
			exit 1; \
		else \
			if [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
			cd ${DISTDIR}/${DIST_SUBDIR} ; \
			unset CVS_RSH CVS_SERVER || ${TRUE} ; \
			${ECHO_MSG} ">> Attempting to CVS update from ${CVSROOT}." ;\
			if ${CVS_CMD} -d ${CVSROOT} up -Pd gdb-5.3 ; \
			then \
				( ${ECHO} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
				exit ; \
			fi ; \
			${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
			${ECHO_MSG} ">> Please try again later."; \
			exit 1; \
			fi; \
		fi; \
	fi;

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR}/gdb-5.3 ; ${PAX} -pe -rwt . ${WRKSRC}

.include "../../lang/gcc3-ada/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
