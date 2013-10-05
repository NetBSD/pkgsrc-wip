# $NetBSD: Makefile,v 1.3 2013/10/05 14:32:12 slitvinov Exp $
#

DISTNAME=	ledger-2.6.3
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ledger/}

MAINTAINER=	jkj@kapsi.fi
HOMEPAGE=	http://wiki.github.com/jwiegley/ledger
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
