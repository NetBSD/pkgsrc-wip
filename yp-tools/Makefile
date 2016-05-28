# $NetBSD: Makefile,v 1.4 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=		yp-tools-2.8
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.us.kernel.org/pub/linux/utils/net/NIS/ \
			ftp://ftp.kernel.org/pub/linux/utils/net/NIS/ \
			http://www.de.kernel.org/pub/linux/utils/net/NIS/ \
			ftp://ftp.kr.kernel.org/pub/linux/utils/net/NIS/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux-nis.org/nis/yp-tools/
COMMENT=		Linux NIS (YP) Tools

ONLY_FOR_PLATFORM=	Linux-*-* # uses glibc header rpcsvc/ypclnt.h


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
