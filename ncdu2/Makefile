# $NetBSD: Makefile,v 1.16 2023/01/03 13:29:49 wiz Exp $

DISTNAME=	ncdu-2.2.1
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

BROKEN=		"Does not support zig-0.10.0."

.include "../../mk/curses.buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
