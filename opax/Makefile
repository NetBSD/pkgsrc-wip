# $NetBSD: Makefile,v 1.1.1.1 2003/06/15 01:06:26 jeremy-c-reed Exp $

DISTNAME=	pax-3.1
PKGNAME=	o${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.suse.com/pub/people/kukuk/pax/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.suse.de/us/private/products/suse_linux/i386/packages_personal/pax.html
COMMENT=	POSIX standard archive tool (port of OpenBSD's pax)

# Uses DEFTAPE from Linux /usr/include/sys/mtio.h
ONLY_FOR_PLATFORM=	Linux-*-*

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"

