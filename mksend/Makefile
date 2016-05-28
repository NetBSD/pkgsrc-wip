# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:28 othyro Exp $
#

DISTNAME=		mksend-0.5.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.nopcode.org/prj/mksend/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nopcode.org/?t=mksend
COMMENT=		Network testing tool for capture and generate packets


GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

.include "../../wip/libparsifal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
