# $NetBSD: Makefile,v 1.1.1.2 2006/02/04 12:12:28 lkundrak Exp $

DISTNAME=		chmlib-0.37.4
CATEGORIES=		textproc
MASTER_SITES=		http://morte.jedrea.com/~jedwin/projects/chmlib
EXTRACT_SUFX=		.tbz

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://morte.jedrea.com/~jedwin/projects/chmlib
COMMENT=		Library for accessing MS HTML Help files

WRKSRC=			${WRKDIR}/chmlib-0.37
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes


.include "../../mk/bsd.pkg.mk"
