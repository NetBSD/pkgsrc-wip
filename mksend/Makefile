# $NetBSD: Makefile,v 1.1.1.1 2005/02/09 20:26:46 poppnk Exp $
#

DISTNAME=		mksend-0.5.2
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.nopcode.org/prj/mksend/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mksend
COMMENT=		Network testing tool for capture and generate packets

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

.include "../../wip/libparsifal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
