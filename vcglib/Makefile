# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Thu Sep  8 08:03:09 CDT 2016               #
###########################################################

###########################################################
# Unconverted and partially converted FreeBSD port syntax:

## Created by: Jason Bacon <pkgsrc-users@NetBSD.org>
## $FreeBSD$
#DISTVERSIONPREFIX=	v
##LICENSE=	unspecified
#do-install:
#	${MKDIR} ${DESTDIR}${PREFIX}/include/vcg
#	cd ${WRKSRC}/vcg && pax -rw/include/vcg
#	cd ${WRKSRC}/docs && pax -rw
#	cd ${WRKSRC} && pax -rw
#.include <bsd.port.mk>

DISTNAME=	vcglib-${PORTVERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cnr-isti-vclab/}
GITHUB_PROJECT=	vcglib
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
HOMEPAGE=	http://vcg.isti.cnr.it/vcglib/
COMMENT=	Template library for manipulation of triangle meshes
LICENSE=	gnu-gpl-v3

# Test and change if necessary.
# MAKE_JOBS_SAFE=	no

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax
NO_BUILD=	yes

FETCH_USING=	curl

PORTVERSION=	1.0.0
DATADIR=	${PREFIX}/share/vcglib
DOCSDIR=	${PREFIX}/share/doc/vcglib
EXAMPLESDIR=	${PREFIX}/share/examples/vcglib

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/vcg && ${PAX} -rw * ${DESTDIR}${PREFIX}/include/vcg
	cd ${WRKSRC}/docs && ${PAX} -rw * ${DESTDIR}${PREFIX}/share/doc/vcglib
	cd ${WRKSRC} && ${PAX} -rw apps ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw img ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw wrap ${DESTDIR}${DATADIR}
# Sets OPSYS, OS_VERSION, MACHINE_ARCH, etc..
# .include "../../mk/bsd.prefs.mk"

# Keep this if there are user-selectable options.
# .include "options.mk"

# Specify which directories to create before install.
# You should only need this if using your own install target.
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1 share/doc share/examples

# Linux doesn't have zlib in the base, so just in case...
# .include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
