# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 11:16:47 cheusov Exp $
#

DISTNAME=	fakeroot_1.14.4.orig
PKGNAME=	${DISTNAME:S/.orig$//:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://packages.debian.org/sid/fakeroot
COMMENT=	Run a command faking root privileges for file manipulation

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fakeroot-1.14.4
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
