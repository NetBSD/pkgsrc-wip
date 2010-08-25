# $NetBSD: Makefile,v 1.5 2010/08/25 19:41:28 cheusov Exp $
#

DISTNAME=	mawk-1.3.4
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vle@gmx.net
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		mawk_test fpe_test

GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=		${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
