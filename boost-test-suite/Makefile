# $NetBSD: Makefile,v 1.3 2009/03/05 15:49:48 brook1 Exp $

DISTNAME=		boost-test-suite-20090302
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER?=		brook@nmsu.edu
HOMEPAGE?=		http://www.boost.org/
COMMENT?=		Run the Boost test suite

# XXX - yet to be tested
# PKG_INSTALLATION_TYPES=	overwrite pkgviews
# PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		ftp pax patch

# XXX - why are these not defined already?
FTP=			${TOOLS_PLATFORM.ftp}
HOSTNAME=		${TOOLS_PLATFORM.hostname}

BOOST_USER?=		${USER}
BOOST_TEST_BASEDIR?=	/var/boost

NO_CHECKSUM=		yes
CHECK_PERMS=		no
NO_BUILD=		yes
DESCR_SRC=		${WRKSRC}/DESCR

SUBST_CLASSES+=			fix-files
SUBST_STAGE.fix-files=		pre-configure
SUBST_MESSAGE.fix-files=	Customizing files
SUBST_FILES.fix-files+=		DESCR
SUBST_FILES.fix-files+=		boost-test-suite boost-test-suite.1
SUBST_FILES.fix-files+=		comment.html.in patch_boost

SUBST_VARS.fix-files+=		BASENAME
SUBST_VARS.fix-files+=		CAT
SUBST_VARS.fix-files+=		CC
SUBST_VARS.fix-files+=		CP
SUBST_VARS.fix-files+=		CXX
SUBST_VARS.fix-files+=		EXPR
SUBST_VARS.fix-files+=		FTP
SUBST_VARS.fix-files+=		GREP
SUBST_VARS.fix-files+=		HOSTNAME
SUBST_VARS.fix-files+=		MKDIR
SUBST_VARS.fix-files+=		PATCH
SUBST_VARS.fix-files+=		PYTHONBIN
SUBST_VARS.fix-files+=		RM
SUBST_VARS.fix-files+=		SED
SUBST_VARS.fix-files+=		TR
SUBST_VARS.fix-files+=		UNAME

SUBST_VARS.fix-files+=		BOOST_TEST_BASEDIR
SUBST_VARS.fix-files+=		BOOST_TOOLSET
SUBST_VARS.fix-files+=		LIBDATA_DIR
SUBST_VARS.fix-files+=		PREFIX

LIBDATA_DIR=			${PREFIX}/libdata/boost-test-suite

INSTALLATION_DIRS+=		libdata sbin

do-extract:
	@${MKDIR} -p ${WRKSRC} ${WRKSRC}/patches.dist
	@${CP} DESCR ${WRKSRC}
	@${CP} -R ${FILESDIR}/* ${WRKSRC}
	@${CP} -R ${PATCHDIR}/* ${WRKSRC}/patches.dist
	@${CHMOD} 444 ${WRKSRC}/patches.dist/*
	@${RM} -rf ${WRKSRC}/CVS ${WRKSRC}/patches.dist/CVS

# patches/* are patches to apply during the testing, not to the package itself
do-patch:		# no patches to apply

do-install:
	${INSTALL_DATA_DIR} ${LIBDATA_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/boost-test-suite ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/boost-test-suite.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/patch_boost ${LIBDATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/comment.html.in ${LIBDATA_DIR}
	${CP} -Rp ${WRKSRC}/patches.dist ${LIBDATA_DIR}

.include "../../devel/boost-build/toolset.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
