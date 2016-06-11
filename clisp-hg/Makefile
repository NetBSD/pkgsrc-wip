# $NetBSD: Makefile,v 1.31 2014/10/09 14:06:26 thomasklausner Exp $
#

DISTNAME=		clisp-2.49
PKGNAME=		clisp-2.49.99 # needed because of cvs-package.mk
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation
LICENSE=		gnu-gpl-v2

HG_REPOSITORIES=	clisp
HG_REPO.clisp=		http://clisp.hg.sourceforge.net:/cvsroot/clisp
WRKSRC=			${WRKDIR}/clisp

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64
NOT_FOR_PLATFORM+=	*-*-arm

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		.
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
BUILD_DIRS=		src
#USE_TOOLS+=		groff
UNLIMIT_RESOURCES=	datasize stacksize

USE_GNU_CONFIGURE_HOST=	NO	# work around broken reasoning: "configure --host=..." => cross-building
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--fsstnd=netbsd
#CONFIGURE_ARGS+=	--without-included-regex	# see options
CONFIGURE_ARGS+=	--with-gettext
MAKE_FLAGS+=		docdir=${PREFIX}/share/doc/${PKGBASE}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		elispdir="${PREFIX}/share/${PKGBASE}/emacs"
MAKE_FLAGS+=		vimdir="${PREFIX}/share/${PKGBASE}/vim"

TEST_TARGET=		check mod-check

# Avoid building PDF documentation (it requires Ghostscript):
CONFIGURE_ENV+=		PS2PDF= ac_cv_prog_PS2PDF=
#USE_TOOLS+=		ps2pdf	# to build PDF documentation

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mx86_64} || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-mmap
.endif

CONFIGURE_ARGS+=	--with-dynamic-modules

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigsegv+=	libsigsegv>=2.4
.include "../../devel/libsigsegv/buildlink3.mk"

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
