# $NetBSD: Makefile,v 1.1.1.1 2011/02/24 19:12:20 ryo-on Exp $
#

DISTNAME=	pstreams-0.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstreams/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pstreams.sourceforge.net/
COMMENT=	POSIX Process Control in C++
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

USE_TOOLS+=	perl:build

INSTALL_MAKE_FLAGS=	prefix=${PREFIX}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
