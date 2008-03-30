# $NetBSD: Makefile,v 1.4 2008/03/30 00:19:16 cheusov Exp $
#

DISTNAME=	mawk-1.3.3
PKGNAME=	${DISTNAME:S/mawk/mawk-uxre/}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/languages/mawk/

MAINTAINER=	cheusov@tut.by
COMMENT=	AWK clone by Mike Brennan

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf213

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

BUILD_TARGET=		mawk_and_test

GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
TEST_TARGET=		mawk_test fpe_test
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=		${CFLAGS:S/-ffast-math//}

LDFLAGS+=		-luxre

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mawk ${DESTDIR}${PREFIX}/bin/mawk-uxre
	${INSTALL_MAN} ${WRKSRC}/man/mawk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mawk-uxre.1

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
