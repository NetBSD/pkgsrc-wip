# $NetBSD$

VERSION=	1.4.0
DISTNAME=	mozart-${VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mozart.github.io/
COMMENT=	Mozart Programming System
LICENSE=	mit # with modifications

GIT_REPOSITORIES=	mozart
GIT_REPO.mozart=	https://github.com/mozart/mozart.git
WRKSRC=			${WRKDIR}/mozart

# Does not build on 64bit platforms (still not ported)
NOT_FOR_PLATFORM=	*-*-x86_64

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison gmake perl

USE_LANGUAGES=	c c++

GNU_CONFIGURE_PREFIX=	${DESTDIR}${PREFIX}/oz	# XXX: Kludge to handle DESTDIR
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--disable-contrib
CONFIGURE_ARGS+=	--disable-doc
CONFIGURE_ARGS+=	--disable-compile-elisp

# XXX: bootstrap before building... Should be fixed in the mozart
# XXX: Makefile instead of doing that here.
pre-build:
	cd ${WRKSRC} && ${GMAKE} bootstrap

# Fix ownership and permissions
post-install:
	${FIND} ${DESTDIR}${PREFIX}/oz -exec ${CHOWN} ${ROOT_USER}:${ROOT_GROUP} {} +
	${CHMOD} -R u=rwX,go=rX ${DESTDIR}${PREFIX}/oz
	${CHMOD} -x ${DESTDIR}${PREFIX}/oz/platform/${LOWER_OPSYS}-${MACHINE_GNU_ARCH}/wish/*/*
	${CHMOD} -x ${DESTDIR}${PREFIX}/oz/include/*

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
