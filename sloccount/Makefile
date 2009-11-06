# $NetBSD: Makefile,v 1.1 2009/11/06 11:46:43 khorben Exp $

DISTNAME=	sloccount-2.26
CATEGORIES=	devel
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.dwheeler.com/sloccount/
COMMENT=	Counting physical Source Lines of Code (SLOC)

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
