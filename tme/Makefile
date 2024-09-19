# $NetBSD: Makefile,v 1.14 2015/07/16 08:09:01 phabrics Exp $

DISTNAME=	tme-0.10
CATEGORIES=	emulators
MASTER_SITES=	http://phabrics.com/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	phabrics@phabrics.com

MAKE_JOBS_SAFE=		no

HOMEPAGE=	http://www.phabrics.com/
COMMENT=	The Machine Emulator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run pkg-config bison

.if (${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	--disable-recode
.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
