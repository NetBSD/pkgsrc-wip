# $NetBSD: Makefile,v 1.3 2006/02/02 12:10:15 poppnk Exp $
#

DISTNAME=		ejourn-0.4.1
CATEGORIES=		misc
MASTER_SITES=		http://www.public.iastate.edu/~chris129/code/ejourn/
EXTRACT_SUFX=	.tar.bz2

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
