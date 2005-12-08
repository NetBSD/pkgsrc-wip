# $NetBSD: Makefile,v 1.1.1.1 2005/12/08 16:52:29 jsonn Exp $
#

DISTNAME=	dfuibe_installer-1.1.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI BSD Installer backend

USE_LIBTOOL=	yes
USE_TOOL+=	msgfmt

.include "../../wip/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"
.include "../../wip/libinstaller/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
