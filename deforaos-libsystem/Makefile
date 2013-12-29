# $NetBSD: Makefile,v 1.11 2013/12/29 16:54:48 khorben Exp $
#

DISTNAME=	libSystem-0.1.6
PKGNAME=	deforaos-libsystem-0.1.6
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3527/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL=${INSTALL}

# Don't use non-portable ${INSTALL} arguments
SUBST_CLASSES+=		nodashes
SUBST_STAGE.nodashes=	pre-configure
SUBST_FILES.nodashes=	include/Makefile include/System/Makefile
SUBST_FILES.nodashes+=	src/Makefile tools/Makefile
SUBST_SED.nodashes=	-e '/INSTALL/s/ -- / /'

LDFLAGS.SunOS+=	-lresolv

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
