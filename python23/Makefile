# $NetBSD: Makefile,v 1.3 2003/08/04 08:55:02 marc Exp $
#

DISTNAME=	Python-2.3
PKGNAME=	python23-2.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.python.org/
COMMENT=	High-level object-oriented programming language

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS=	sunos
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "IRIX"
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}
.else
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

#INSTALL_TARGET=	altinstall

#post-extract:
#	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc23

# XXX should be done by the Python install process
post-install:
	${LN} -s ${PREFIX}/lib/libpython2.3.so.1.0 ${PREFIX}/lib/libpython2.3.so

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=      LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
