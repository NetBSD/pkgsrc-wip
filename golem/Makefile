# $NetBSD: Makefile,v 1.2 2003/04/06 11:41:21 thomasklausner Exp $
#

DISTNAME=	golem-0.0.5
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	reide@darkest.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

post-install:
	${GZIP_CMD} -d ${PREFIX}/man/man1/golem.1.gz
	${CHMOD} 644 ${PREFIX}/man/man1/golem.1

.include "../../mk/bsd.pkg.mk"
