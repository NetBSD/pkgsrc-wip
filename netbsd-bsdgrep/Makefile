# $NetBSD: Makefile,v 1.5 2008/03/30 13:31:05 cheusov Exp $
#

DISTNAME=	netbsd-bsdgrep-20070105
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD src/usr.bin/grep

PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_FEATURES=		nbcompat

MAKE_ENV+=	MKCATPAGES=no

CPPFLAGS+=	-Dlint

post-patch:
	sed -e 's|grep|nbgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/nbgrep.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
