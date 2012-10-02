# $NetBSD: Makefile,v 1.1 2012/10/02 13:01:08 makoto Exp $

DISTNAME=	tqsllib-2_2
PKGNAME=	tqsllib-2.2
CATEGORIES=     ham
MASTER_SITES=	http://www.arrl.org/files/file/LoTW%20Instructions/
#LICENSE=	arrl

EXTRACT_SUFX=	_tar.gz

MAINTAINER=     makoto@ki.nu
HOMEPAGE=       http://www.arrl.org/files/file/LoTW%20Instructions/
COMMENT=        Tqsl library for ARRL LoTW
WRKSRC=         ${WRKDIR}/${PKGNAME}

USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=          yes

.include "../../mk/bsd.pkg.mk"
