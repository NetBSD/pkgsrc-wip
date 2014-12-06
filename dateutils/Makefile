# $NetBSD: Makefile,v 1.2 2014/12/06 04:57:53 makoto Exp $

DISTNAME=	v0.3.1
PKGNAME=	${DISTNAME:S/^v/dateutils-/}
CATEGORIES=	time
MASTER_SITES=	http://github.com/hroptatyr/dateutils/archive/
DIST_SUBDIR=	dateutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fresse.org/dateutils/
COMMENT=	Command line tools for working with dates
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config automake autoreconf gmake makeinfo bison
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libdut.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

pre-configure:
	(cd ${WRKSRC}; autoreconf -i )

post-build:
	(cd ${WRKSRC}/lib; ${GMAKE})

#post-install:
#	(cd ${WRKSRC}/lib; env DESTDIR=${DESTDIR} ${GMAKE} install-libLIBRARIES)

.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
