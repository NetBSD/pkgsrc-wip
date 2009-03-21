# $NetBSD: Makefile,v 1.6 2009/03/21 11:09:49 jihbed Exp $
#

DISTNAME=	dash-0.5.5.1
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/files/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf autoheader

pre-configure:
	cd ${WRKSRC} && autoheader && autoconf

.include "../../mk/bsd.pkg.mk"
