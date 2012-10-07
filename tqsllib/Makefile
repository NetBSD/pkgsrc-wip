# $NetBSD: Makefile,v 1.5 2012/10/07 17:17:45 asau Exp $

DISTNAME=	tqsllib-2_2
PKGNAME=	tqsllib-2.2
CATEGORIES=	ham
MASTER_SITES=	http://www.arrl.org/files/file/LoTW%20Instructions/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.arrl.org/files/file/LoTW%20Instructions/
COMMENT=	Tqsl library for ARRL LoTW
#LICENSE=	arrl

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
