# $NetBSD: Makefile,v 1.3 2009/12/21 20:38:53 cheusov Exp $
#

DISTNAME=	mawk-1.3.4
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=		vle@gmx.net
COMMENT=		AWK clone by Mike Brennan

LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

TEST_TARGET=		mawk_test fpe_test

GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
