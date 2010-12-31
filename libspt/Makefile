# $NetBSD: Makefile,v 1.1.1.1 2010/12/31 16:21:21 makoto Exp $

DISTNAME=	libspt-1.1

CATEGORIES=     devel
MASTER_SITES=   http://www.j10n.org/libspt/

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.j10n.org/libspt/
COMMENT=	Provide unpriviliged secure pty

USE_LIBTOOL=	yes
PKG_DESTDIR_SUPPORT=    user-destdir
GNU_CONFIGURE=  yes

SPECIAL_PERMS=	libexec/sptagent root wheel 4755

.include "../../mk/bsd.pkg.mk"
