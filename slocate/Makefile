# $NetBSD: Makefile,v 1.7 2006/05/01 01:32:12 shattered Exp $
#

DISTNAME=		slocate-2.7
CATEGORIES=		sysutils
MASTER_SITES=		http://slocate.trakker.ca/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://slocate.trakker.ca/
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
