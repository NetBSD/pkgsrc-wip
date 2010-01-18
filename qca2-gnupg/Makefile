# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:30 thomasklausner Exp $

DISTNAME=	qca-gnupg-2.0.0-beta2
PKGNAME=	qca2-gnupg-${DISTNAME:S/-beta/beta/:C/.*-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - GnuPG plugin

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--with-qca=${QTDIR}
#CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
#CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

.include "../../security/qca2/buildlink3.mk"
.include "../../security/gnupg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
