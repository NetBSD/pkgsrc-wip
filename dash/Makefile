# $NetBSD: Makefile,v 1.5 2008/12/21 22:07:19 cheusov Exp $
#

DISTNAME=	dash-0.5.4
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/files/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf

pre-configure:
	cd ${WRKSRC} && autoheader && autoconf

.include "../../mk/bsd.pkg.mk"
