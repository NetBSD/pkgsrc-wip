# $NetBSD: Makefile,v 1.1.1.1 2006/12/02 17:00:57 dhowland Exp $
#

DISTNAME=		xar-1.4
CATEGORIES=		archivers
MASTER_SITES=		http://www.opendarwin.org/projects/xar/
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.opendarwin.org/projects/xar/
COMMENT=		The eXtensible ARchiver

#WRKSRC=			${WRKDIR}/eJourn

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake


#do-configure:
#	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
