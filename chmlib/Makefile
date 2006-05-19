# $NetBSD: Makefile,v 1.3 2006/05/19 16:51:15 ykomatsu Exp $
#

DISTNAME=	chmlib-0.31
CATEGORIES=	devel
MASTER_SITES=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
