# $NetBSD: Makefile,v 1.1.1.1 2009/01/27 15:02:53 shindenmorr Exp $
#

DISTNAME=	pkcs11-helper-1.06
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://www.opensc-project.org/pkcs11-helper/
COMMENT=	Library that simplifies the interaction with PKCS#11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf gmake

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:                                                                                                                                                           
	cd ${WRKSRC} && autoreconf  

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
