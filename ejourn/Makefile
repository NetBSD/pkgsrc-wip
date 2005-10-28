# $NetBSD: Makefile,v 1.2 2005/10/28 04:11:47 dhowland Exp $
#

DISTNAME=		ejourn-0.2.5
CATEGORIES=		misc
MASTER_SITES=		http://www.public.iastate.edu/~chris129/code/elog/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.public.iastate.edu/~chris129/code/elog/
COMMENT=		Application to help track a journal or diary

WRKSRC=			${WRKDIR}/ejourn

USE_TOOLS+=		gmake

do-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
