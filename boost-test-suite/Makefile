# $NetBSD: Makefile,v 1.13 2014/10/09 14:06:26 thomasklausner Exp $

DISTNAME=		boost-test-suite-20090305
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER?=		brook@nmsu.edu
HOMEPAGE?=		https://www.boost.org/
COMMENT?=		Run the Boost test suite
LICENSE=		boost-license

USE_TOOLS+=		ftp pax patch

FTP=			${TOOLS_PLATFORM.ftp}
HOSTNAME=		${TOOLS_PLATFORM.hostname}
TEE=			${TOOLS_PLATFORM.tee}

BOOST_TEST_BASEDIR?=	${VARBASE}/boost

CHECK_PERMS=		no
NO_BUILD=		yes

SUBST_CLASSES+=			fix-files
SUBST_STAGE.fix-files=		pre-configure
SUBST_MESSAGE.fix-files=	Customizing files
SUBST_FILES.fix-files+=		boost-test-suite boost-test-suite.1
SUBST_FILES.fix-files+=		comment.html.in patch_boost

SUBST_VARS.fix-files+=		BASENAME
SUBST_VARS.fix-files+=		CAT
SUBST_VARS.fix-files+=		CC
SUBST_VARS.fix-files+=		CP
SUBST_VARS.fix-files+=		CXX
SUBST_VARS.fix-files+=		DATE
SUBST_VARS.fix-files+=		EXPR
SUBST_VARS.fix-files+=		FTP
SUBST_VARS.fix-files+=		GREP
SUBST_VARS.fix-files+=		HOSTNAME
SUBST_VARS.fix-files+=		INSTALL
SUBST_VARS.fix-files+=		MKDIR
SUBST_VARS.fix-files+=		PATCH
SUBST_VARS.fix-files+=		PYTHONBIN
SUBST_VARS.fix-files+=		RM
SUBST_VARS.fix-files+=		SED
SUBST_VARS.fix-files+=		TEE
SUBST_VARS.fix-files+=		TR
SUBST_VARS.fix-files+=		UNAME

SUBST_VARS.fix-files+=		BOOST_TEST_BASEDIR
SUBST_VARS.fix-files+=		BOOST_TOOLSET
SUBST_VARS.fix-files+=		LIBDATA_DIR
SUBST_VARS.fix-files+=		PREFIX

LIBDATA_DIR=			${PREFIX}/libdata/boost-test-suite

INSTALLATION_DIRS+=		libdata ${PKGMANDIR}/man1 sbin

FILES+=				boost-test-suite boost-test-suite.1
FILES+=				comment.html.in patch_boost
PATCHES+=			index patch-aa

do-extract:
	${MKDIR} -p ${WRKSRC} ${WRKSRC}/patches
.for f in ${FILES}
	${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor
.for f in ${PATCHES}
	${CP} ${PATCHDIR}/${f} ${WRKSRC}/patches
.endfor

# patches/* are patches to apply during the testing, not to the package itself
do-patch:		# no patches to apply

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${LIBDATA_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${LIBDATA_DIR}/patches
	${INSTALL_SCRIPT} ${WRKSRC}/boost-test-suite ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/boost-test-suite.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/patch_boost ${DESTDIR}${LIBDATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/comment.html.in ${DESTDIR}${LIBDATA_DIR}
	cd ${WRKSRC}/patches && ${PAX} -rw * ${DESTDIR}${LIBDATA_DIR}/patches

.include "../../devel/boost-build/toolset.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
