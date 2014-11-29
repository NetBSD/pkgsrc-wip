# $NetBSD: Makefile,v 1.1 2014/11/29 01:12:06 krytarowski Exp $

DISTNAME=	radare2-0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://www.radare.org/get/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radare.org/
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
