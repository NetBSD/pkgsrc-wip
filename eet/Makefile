# $NetBSD: Makefile,v 1.16 2013/11/09 14:29:45 roelants Exp $
#

DISTNAME=	eet-1.7.9
CATEGORIES=	devel archivers
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Data encode/decode and storage library

LICENSE=	2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

INSTALLATION_DIRS=	share/doc/eet

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/AUTHORS \
	    ${DESTDIR}${PREFIX}/share/doc/eet

.include "../../wip/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
