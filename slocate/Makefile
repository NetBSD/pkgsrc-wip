# $NetBSD: Makefile,v 1.4 2004/02/12 07:24:09 minskim Exp $
#

DISTNAME=		slocate-2.7
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.geekreview.org/slocate/src/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.geekreview.org/slocate/
COMMENT=		Secure Locate

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

MANCOMPRESSED=		locate.1.gz

pre-configure:
.for f in aclocal.m4 Makefile.in configure stamp-h.in
	${TOUCH} ${WRKSRC}/$f
.endfor

.include "../../mk/bsd.pkg.mk"
