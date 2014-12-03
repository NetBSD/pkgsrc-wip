# $NetBSD: Makefile,v 1.2 2014/12/03 20:47:44 krytarowski Exp $

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
CONFIGURE_ARGS+=	--with-sysmagic
USE_TOOLS+=	gmake

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
