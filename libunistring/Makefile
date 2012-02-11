# $NetBSD: Makefile,v 1.2 2012/02/11 07:17:20 realzhtw Exp $
#

DISTNAME=	libunistring-0.9.3
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/libunistring/

MAINTAINER=	a@zta.lk
HOMEPAGE=	http://www.gnu.org/software/libunistring/
COMMENT=	Library that provides functions for manipulating Unicode strings
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
