# $NetBSD: Makefile,v 1.5 2012/11/23 22:33:47 othyro Exp $

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
