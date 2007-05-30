# $NetBSD: Makefile,v 1.1.1.1 2007/05/30 18:23:41 hoka_adam Exp $

DISTNAME=	bsdinstaller-2.0
CATEGORIES=	wip
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=     adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.org
COMMENT=	BSD Installer meta-package.

DEPENDS+=	libdfui>=4.1:../../wip/libdfui
DEPENDS+=       libinstaller>=5.1:../../wip/libinstaller
DEPENDS+=	dfuibe-installer>=1.1.7:../../wip/dfuibe_installer
DEPENDS+=	dfuife-curses>=1.5.1:../../wip/dfuife_curses

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
