# $NetBSD: Makefile,v 1.3 2008/01/18 04:30:15 tnn2 Exp $
#

DISTNAME=	libssh2-0.17
PKGREVISION=	1
CATEGORIES=	wip security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libssh2/}

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://libssh2.sourceforge.net/
COMMENT=	SSH2 protocol library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include	"options.mk"

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
