# $NetBSD: Makefile,v 1.1.1.1 2009/03/02 08:09:02 jkjuopperi Exp $
#

DISTNAME=	ledger-2.6.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ledger/}

MAINTAINER=	jkj@kapsi.fi
HOMEPAGE=	http://ledger.sourceforge.net/
COMMENT=	Double-entry accounting system for command-line

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

PKG_DESTDIR_SUPPORT=	destdir

# configure script seems to require c
USE_LANGUAGES=	c++ c

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
