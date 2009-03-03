# $NetBSD: Makefile,v 1.1 2009/03/03 16:02:38 brook1 Exp $

DISTNAME=		boost-test-suite-20090302
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER?=		brook@nmsu.edu
HOMEPAGE?=		http://www.boost.org/
COMMENT?=		Run the Boost test suite

# PKG_INSTALLATION_TYPES=	overwrite pkgviews
# PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax patch

BASENAME?=		/usr/bin/basename
EXPR?=			/bin/expr
FTP?=			/usr/bin/ftp
GREP?=			/usr/bin/grep
HOSTNAME?=		/bin/hostname
SED?=			/usr/bin/sed
TR?=			/usr/bin/tr
UNAME?=			/usr/bin/uname

HOST!=			${HOSTNAME}

BASEDIR=		${PREFIX}/var/boost

BOOST_USER?=		${USER}
BOOST_TOOLSET?=		gcc			# XXX - should be detected?

NO_CHECKSUM=		yes
CHECK_PERMS=		no
NO_BUILD=		yes
DESCR_SRC=		${WRKSRC}/DESCR

SUBST_CLASSES+=			fix-files
SUBST_STAGE.fix-files=		pre-configure
SUBST_MESSAGE.fix-files=	Customizing files
SUBST_FILES.fix-files+=		DESCR
SUBST_FILES.fix-files+=		boost-test-suite comment.html.in patch_boost

SUBST_VARS.fix-files+=		BASEDIR
SUBST_VARS.fix-files+=		BASENAME
SUBST_VARS.fix-files+=		CAT
SUBST_VARS.fix-files+=		CC
SUBST_VARS.fix-files+=		CXX
SUBST_VARS.fix-files+=		EXPR
SUBST_VARS.fix-files+=		FTP
SUBST_VARS.fix-files+=		GREP
SUBST_VARS.fix-files+=		HOSTNAME
SUBST_VARS.fix-files+=		MKDIR
SUBST_VARS.fix-files+=		PATCH
SUBST_VARS.fix-files+=		PREFIX
SUBST_VARS.fix-files+=		PYTHONBIN
SUBST_VARS.fix-files+=		RM
SUBST_VARS.fix-files+=		SED
SUBST_VARS.fix-files+=		TR
SUBST_VARS.fix-files+=		UNAME

SUBST_VARS.fix-files+=		BOOST_TOOLSET

INSTALLATION_DIRS+=		${BASEDIR}

INSTALL_FILES+=			comment.html.in

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
	${INSTALL_SCRIPT} ${WRKSRC}/boost-test-suite ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/boost-test-suite.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/patch_boost ${BASEDIR}
.for f in ${INSTALL_FILES}
	cd ${WRKSRC} && ${INSTALL_DATA} $f ${BASEDIR}/$f
.endfor
	${CP} -Rp ${WRKSRC}/patches.dist ${BASEDIR}/patches.dist
	${CHOWN} -R ${BOOST_USER} ${BASEDIR}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
