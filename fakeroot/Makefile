# $NetBSD: Makefile,v 1.3 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=	fakeroot_1.14.4.orig
PKGNAME=	${DISTNAME:S/.orig$//:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://packages.debian.org/sid/fakeroot
COMMENT=	Run a command faking root privileges for file manipulation

LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/fakeroot-1.14.4
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
