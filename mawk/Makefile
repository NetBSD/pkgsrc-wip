# $NetBSD: Makefile,v 1.9 2012/10/08 14:00:39 asau Exp $
#

DISTNAME=	mawk-1.3.4-20100625
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@NetBSD.org
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

TEST_TARGET=		mawk_test fpe_test

GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=		${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
