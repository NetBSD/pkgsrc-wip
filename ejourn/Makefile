# $NetBSD: Makefile,v 1.4 2006/07/30 23:14:48 dhowland Exp $
#

DISTNAME=		ejourn-0.4.2
CATEGORIES=		misc
MASTER_SITES=		http://www.public.iastate.edu/~chris129/code/ejourn/Downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.public.iastate.edu/~chris129/code/elog/
COMMENT=		Application to help track a journal or diary

WRKSRC=			${WRKDIR}/eJourn

USE_TOOLS+=		gmake

do-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
