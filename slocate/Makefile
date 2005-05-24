# $NetBSD: Makefile,v 1.6 2005/05/24 10:31:42 rillig Exp $
#

DISTNAME=		slocate-2.7
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.geekreview.org/slocate/src/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.geekreview.org/slocate/
COMMENT=		Secure Locate

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

MANCOMPRESSED=		locate.1.gz

pre-configure:
.for f in aclocal.m4 Makefile.in configure stamp-h.in
	${TOUCH} ${WRKSRC}/$f
.endfor

.include "../../mk/bsd.pkg.mk"
