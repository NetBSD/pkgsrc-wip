# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:04 tvierling Exp $
#

DISTNAME=		mksend-0.5.3
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.nopcode.org/prj/mksend/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mksend
COMMENT=		Network testing tool for capture and generate packets

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

.include "../../wip/libparsifal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
