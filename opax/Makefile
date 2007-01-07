# $NetBSD: Makefile,v 1.3 2007/01/07 21:27:38 shattered Exp $

DISTNAME=	pax-3.4
PKGNAME=	o${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.suse.com/pub/people/kukuk/pax/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.novell.com/products/linuxpackages/suselinux/pax.html
COMMENT=	POSIX standard archive tool (port of OpenBSD's pax)

# Uses DEFTAPE from Linux /usr/include/sys/mtio.h
ONLY_FOR_PLATFORM=	Linux-*-*

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"

