# $NetBSD: Makefile,v 1.1.1.1 2005/12/08 16:54:08 jsonn Exp $
#

DISTNAME=	dfuife_curses-1.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI curses frontend

USE_LIBTOOL=	yes
USE_TOOL+=	msgfmt
USE_NCURSES=	yes

.include "../../wip/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"
.include "../../wip/libinstaller/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
