# $NetBSD: Makefile,v 1.4 2010/01/27 10:53:40 thomasklausner Exp $
#

DISTNAME=	mawk-1.3.4
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=		vle@gmx.net
COMMENT=		AWK clone by Mike Brennan
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		mawk_test fpe_test

GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
