# $NetBSD: Makefile,v 1.4 2006/07/20 13:25:31 obache Exp $
#

DISTNAME=	chmlib-0.38
CATEGORIES=	devel
MASTER_SITES=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

#USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE==		yes

PTHREAD_OPTS=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
