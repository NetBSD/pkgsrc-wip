# $NetBSD: Makefile,v 1.3 2012/10/07 16:23:15 asau Exp $

DISTNAME=	sloccount-2.26
CATEGORIES=	devel
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.dwheeler.com/sloccount/
COMMENT=	Counting physical Source Lines of Code (SLOC)

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex perl

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
