# $NetBSD: Makefile,v 1.1 2015/02/22 15:50:27 othyro Exp $
#

DISTNAME=	rng-tools-5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkernel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gkernel/
COMMENT=	Random collection of Linux kernel-related projects and source code
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "options.mk"

#LIBS+=		-largp # XXX for when this package is cross-platform (if ever)
#
#pre-configure:
#	set -e; cd ${WRKSRC};
#		aclocal; autoheader; automake -a --foreign -i; autoconf
#
#.include "../../devel/argp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
