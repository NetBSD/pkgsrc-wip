# $NetBSD$

DISTNAME=	numactl-2.0.11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/www/projects/libnuma/download/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	ftp://oss.sgi.com/www/projects/libnuma/download/
COMMENT=	Non Uniform Memory Access tools
#LICENSE=	# TODO: (see mk/license.mk)

# numactl and the demo programs are under the GNU General Public License, v.2
# libnuma is under the GNU Lesser General Public License, v2.1. 

ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/numactl-2.0.11
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
