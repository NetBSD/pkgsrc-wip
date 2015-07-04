# $NetBSD: Makefile,v 1.5 2015/07/04 04:27:32 ryo-on Exp $

DISTNAME=	libassuan-2.2.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=	.tar.bz2
CONFLICTS=	libassuan-[0-9]*

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	http://gnupg.org/related_software/libassuan/index.en.html
COMMENT=	IPC library used by some of the other GnuPG related packages
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
INFO_FILES=		yes

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
