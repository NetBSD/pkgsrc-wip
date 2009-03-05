# $NetBSD: Makefile,v 1.4 2009/03/05 00:38:10 othyro Exp $

DISTNAME=		ilbc-rfc3951
PKGNAME=		ilbc-rfc3951-200412
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://download.savannah.gnu.org/releases/linphone/1.3.x/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ietf.org/rfc/rfc3951.txt
COMMENT=		Internet Low Bit Rate Codec

LICENSE=		GIPS-iLBC-license
RESTRICTED=		Personal distribution only.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++ fortran
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.pkg.mk"
