# $NetBSD: Makefile,v 1.1 2015/01/17 14:30:22 bsiegert Exp $

DISTNAME=	tme-1.0beta_4
CATEGORIES=	emulators
MASTER_SITES=	http://www.phabrics.com/
EXTRACT_SUFX=   .tar.xz

MAINTAINER=	phabrics@phabrics.com

HOMEPAGE=	http://www.phabrics.com/
COMMENT=	TME modified to add features like GTK3 and NPF NAT
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFLICTS=	tme-[0-9]*

.if (${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	--disable-recode
.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
