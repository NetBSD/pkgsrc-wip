# $NetBSD: Makefile,v 1.3 2008/02/05 14:20:58 asau Exp $
#

DISTNAME=	clisp-2.44
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

CONFLICTS+=	clisp-[0-9]*

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64

PKG_INSTALLATION_TYPES= overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		dvipdf gmake
USE_PKGLOCALEDIR=	YES
BUILD_DIRS=		src
#CONFIGURE_ENV+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} CPPFLAGS=${CPPFLAGS:M*:Q}
GNU_CONFIGURE=		YES
UNLIMIT_RESOURCES=	stacksize
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--fsstnd=netbsd
CONFIGURE_ARGS+=	--without-included-regex
CONFIGURE_ARGS+=	--with-gettext
TEST_TARGET=		check
MAKE_ENV+=		TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}
MAKE_FLAGS+=		docdir=${PREFIX}/share/doc/${PKGNAME}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		elispdir="${PREFIX}/share/${PKGNAME}/emacs"
MAKE_FLAGS+=		vimdir="${PREFIX}/share/${PKGNAME}/vim"
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mx86_64} || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-mmap
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigsegv+=	libsigsegv>=2.4
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
