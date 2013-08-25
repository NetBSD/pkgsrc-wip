# $NetBSD: Makefile,v 1.1 2013/08/25 08:16:03 obache Exp $

DISTNAME=	str-0.9.12
PKGNAME=	ossp-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/str/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.ossp.org/pkg/lib/str/
COMMENT=	OSSP str - String Manipulations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

TEST_TARGET=		check

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
