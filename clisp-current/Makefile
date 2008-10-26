# $NetBSD: Makefile,v 1.25 2008/10/26 12:20:27 asau Exp $
#

DISTNAME=		clisp-2.47
PKGNAME=		clisp-2.47.99 # needed because of cvs-package.mk
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation

CVS_REPOSITORIES=	clisp
CVS_ROOT.clisp=		:pserver:anonymous:@clisp.cvs.sourceforge.net:/cvsroot/clisp
WRKSRC=			${WRKDIR}/clisp

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64
NOT_FOR_PLATFORM+=	*-*-arm

PKG_INSTALLATION_TYPES= overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

CONFIGURE_DIRS=		.
USE_GNU_CONFIGURE_HOST=	NO	# work around broken reasoning: "configure --host=..." => cross-building
BUILD_DIRS=		src
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		dvipdf
UNLIMIT_RESOURCES=	stacksize

CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--fsstnd=netbsd
CONFIGURE_ARGS+=	--without-included-regex
CONFIGURE_ARGS+=	--with-gettext
MAKE_FLAGS+=		docdir=${PREFIX}/share/doc/${PKGNAME}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		elispdir="${PREFIX}/share/${PKGNAME}/emacs"
MAKE_FLAGS+=		vimdir="${PREFIX}/share/${PKGNAME}/vim"

TEST_TARGET=		check mod-check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mx86_64} || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-mmap
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigsegv+=	libsigsegv>=2.4
.include "../../devel/libsigsegv25/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
