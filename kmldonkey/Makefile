# $NetBSD: Makefile,v 1.1.1.1 2009/05/07 01:33:52 ficovh Exp $

DISTNAME=	kmldonkey-0.11
CATEGORIES=	local net
MASTER_SITES?=  ${MASTER_SITE_KDE:=apps/KDE3.x/network/}
MAINTAINER=	gallegos@csxxi.net.mx
COMMENT=	Frontend for MLDonkey
HOMEPAGE?=	http://www.kmldonkey.org/

USE_LANGUAGES=	c c++ fortran
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config gmake perl autoconf
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

# Pendientes
# USE_AUTOTOOLS=  libtool:15
# CONFIGURE_ARGS= --program-transform-name=''
# USE_LDCONFIG=   yes

.include	"../../meta-pkgs/kde3/kde3.mk"
.include	"../../x11/kdelibs3/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
