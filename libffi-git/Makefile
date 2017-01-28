# $NetBSD: Makefile,v 1.30 2017/01/28 15:33:25 wiz Exp $

DISTNAME=	libffi-3.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.sourceware.org/libffi/
COMMENT=	Foreign function interface (development version from git)
LICENSE=	mit

GIT_REPOSITORIES=	libffi
GIT_REPO.libffi=	git://github.com/atgreen/libffi.git
WRKSRC=			${WRKDIR}/libffi

BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf automake autoreconf makeinfo gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libffi.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
