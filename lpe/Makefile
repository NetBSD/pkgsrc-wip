# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 11:17:20 xtraeme Exp $
#

DISTNAME=	lpe-1.2.6
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.sasknow.com/pub/ \
		ftp://ftp.twu.net/users/cdsmith/lpe/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://cdsmith.twu.net/professional/opensource/lpe.html
COMMENT=	Small and efficient programmer's editor for UNIX systems

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libslang/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
